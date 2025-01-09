#pragma once
#include <mutex>
#include "SendBuffer.h"

extern class ThreadManager* GThreadManager;
extern class SendBufferManager* GSendBufferManager;
extern thread_local uint32_t MyThreadID;
extern thread_local shared_ptr<SendBufferChunk> LSendBufferChunkRef;

class ThreadManager {
public:
	ThreadManager();
	~ThreadManager();

	static void InitTLS();
	static void DestroyTLS() { };

	void Launch(function<void(void)> callback);
	void Join();

private:
	mutex	_mutex;
	vector<thread> _threads;
};