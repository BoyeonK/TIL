#pragma once
#include <mutex>

extern thread_local uint32_t MyThreadID;
extern class ThreadManager* GThreadManager;

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