#include "RWLock.h"
#include "TLSvariables.h"
#include <thread>
#include <cstdint>
//#include <sysinfoapi.h>
#include <time.h>


void RWLock::WriteLock() {
	const uint32_t TaskThreadId = (_lockFlag.load() & WRITE_THREAD_MASK) >> 16;
	if (MyThreadID == TaskThreadId) {
		_writeCount++;
		return;
	}
	clock_t S_tick = clock();
	//uint64_t S_tick = GetTickCount64();
	const uint32_t desired = (MyThreadID << 16 & WRITE_THREAD_MASK);
	while (true) {
		for (uint32_t trial = 0; trial < MAX_SPIN_COUNT; trial++) {
			uint32_t expected = EMPTY_FLAG;
			if (_lockFlag.compare_exchange_strong(expected, desired)) {
				_writeCount++;
				return;
			}
		}
		if (clock() - S_tick > ACQUIRE_TIMEOUT_TICK) {
			//최대 소요시간 초과시 예외처리
		}
		this_thread::yield();
	}
}

void RWLock::WriteUnlock() {
}

void RWLock::ReadLock() {
}

void RWLock::ReadUnlock() {
}
