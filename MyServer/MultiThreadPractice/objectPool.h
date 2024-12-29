#pragma once
#include <cstdint>
#include <windows.h>
#include <malloc.h>
#include <atomic>

using namespace std;

#ifdef _DEBUG
class counter {
public:
	atomic<uint32_t> _uses = 0;
	atomic<uint32_t> _reserves = 0;
};
#endif

template<typename _Ty>
class objectPool {
public:
	static PSLIST_ENTRY popEntry() {
		PSLIST_ENTRY pEntry = ::InterlockedPopEntrySList(&_poolHeader);
		if (pEntry == nullptr) {
			pEntry = static_cast<PSLIST_ENTRY>(_aligned_malloc(sizeof(SLIST_ENTRY) + _typeSize, 16));
#ifdef _DEBUG
			_counter._uses.fetch_add(1);
#endif
		}
		return pEntry;
	}

	static void pushEntry(PSLIST_ENTRY ptr) {
		::InterlockedPushEntrySList(ptr);
#ifdef _DEBUG
		_counter._uses.fetch_sub(1);
		_counter._reserves.fetch_add(1);
#endif
	}

private:
	alignas(16) static SLIST_HEADER _poolHeader;
	static uint32_t _typeSize;
#ifdef _DEBUG
	static counter _counter;
#endif
};

template<typename _Ty>
uint32_t objectPool<_Ty>::_typeSize = sizeof(_Ty);

template<typename _Ty, typename... Args>
_Ty* P_new(Args&&... args) {
	PSLIST_ENTRY ptr = objectPool<_Ty>::popEntry();
	return reinterpret_cast<_Ty*>(++ptr);
}
