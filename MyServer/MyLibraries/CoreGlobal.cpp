#include "pch.h"
#include "CoreGlobal.h"
#include "SocketUtils.h"
#include "SendBuffer.h"

thread_local uint32_t MyThreadID = 0;
thread_local shared_ptr<SendBufferChunk> LSendBufferChunkRef = nullptr;
ThreadManager* GThreadManager = nullptr;

class CoreGlobal {
public:
	CoreGlobal() {
		GThreadManager = new ThreadManager();
		SocketUtils::Init();
	}

	~CoreGlobal() {
		delete GThreadManager;
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
