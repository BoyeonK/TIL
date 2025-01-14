#include "pch.h"
#include "CoreGlobal.h"
#include "SocketUtils.h"
#include "SendBuffer.h"
#include "JobQueue.h"
#include "GlobalQueue.h"

ThreadManager* GThreadManager = nullptr;
SendBufferManager* GSendBufferManager = nullptr;
GlobalQueue* GlobalJobQueue = nullptr;
thread_local uint32_t MyThreadID = 0;
thread_local shared_ptr<SendBufferChunk> LSendBufferChunkRef = nullptr;
thread_local JobQueue* LCurrentJobQueue = nullptr;

class CoreGlobal {
public:
	CoreGlobal() {
		GThreadManager = new ThreadManager();
		GSendBufferManager = new SendBufferManager();
		GlobalJobQueue = new GlobalQueue();
		SocketUtils::Init();
	}

	~CoreGlobal() {
		delete GThreadManager;
		delete GSendBufferManager;
		SocketUtils::Clear();
	}
} GCoreGlobal;

ThreadManager::ThreadManager() {
	InitTLS();
}

ThreadManager::~ThreadManager() {
	Join();
}

void ThreadManager::InitTLS() {
	//NxtThreadID�� ������ InitTLS�Լ��θ� �����Ǿ����.
	//���� static�Լ� ������ ���� static������ ����
	//�� �Լ� �������� ����� NxtThreadID ������ ����ִ�.
	static atomic<uint32_t> NxtThreadID = 1;
	MyThreadID = NxtThreadID.fetch_add(1);
}

void ThreadManager::Launch(function<void(void)> callback) {
	lock_guard<mutex> guard(_mutex);
	_threads.push_back(thread([=] {
		InitTLS();
		callback();
		DestroyTLS();
		}));
}

void ThreadManager::Join() {
	for (thread& t : _threads) {
		if (t.joinable())
			t.join();
	}
	_threads.clear();
}

void ThreadManager::DoGlobalQueueWork() {
	while (LCurrentJobQueue == nullptr) {
		//uint64_t now = ::GetTickCount64();
		shared_ptr<JobQueue> jobQueue = GlobalJobQueue->Pop();
		if (jobQueue == nullptr)
			break;
		jobQueue->Execute();
	}
}
