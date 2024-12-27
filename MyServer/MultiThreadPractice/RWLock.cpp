#include "pch.h"
#include "RWLock.h"
#include "TLSvariables.h"
#include <thread>
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
			CRASH("spinLock 시간 초과");
			//최대 소요시간 초과시 예외처리
		}
		this_thread::yield();
	}
}

void RWLock::WriteUnlock() {
	if ((_lockFlag.load() & READ_COUNT_MASK) != 0) {
		CRASH("WriteLock 해제 오류. ReadLock이 먼저 해제 되지 않음.")
	}

	const int32_t lockCount = --_writeCount;
	if (lockCount == 0)
		_lockFlag.store(EMPTY_FLAG);
}

void RWLock::ReadLock() {
}

void RWLock::ReadUnlock() {
}
