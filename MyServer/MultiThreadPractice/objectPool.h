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

class poolHeader {
public:
	poolHeader() {
		::InitializeSListHead(&_header);
	}

	~poolHeader() { 
		//TODO :: header와 연결된 모든 LIST 멤버의 소멸자를 호출한다.
	}

	PSLIST_ENTRY popEntry(uint32_t _typeSize) {
		PSLIST_ENTRY pEntry = ::InterlockedPopEntrySList(&_header);
		if (pEntry == nullptr) 
			pEntry = static_cast<PSLIST_ENTRY>(_aligned_malloc(sizeof(SLIST_ENTRY) + _typeSize, 16));
		return pEntry;
	}

	void pushEntry(PSLIST_ENTRY pSE) {
		::InterlockedPushEntrySList(&_header, pSE);
	}

private:
	alignas(16) SLIST_HEADER _header;
};

template<typename _Ty>
class objectPool {
public:
	template<typename... Args>
	static _Ty* alloc(Args&&... args) {
		PSLIST_ENTRY pSE = _poolHeader.popEntry(_typeSize);
		_Ty* ptr = reinterpret_cast<_Ty*>(++pSE);
		new(ptr)_Ty(forward<Args>(args)...);
#ifdef _DEBUG
		_counter._uses.fetch_add(1);
#endif
		return ptr;
	}

	static void dealloc(_Ty* ptr) {
		ptr->~_Ty();
		PSLIST_ENTRY pSE = reinterpret_cast<PSLIST_ENTRY>(ptr) - 1;
		_poolHeader.pushEntry(pSE);
#ifdef _DEBUG
		_counter._uses.fetch_sub(1);
		_counter._reserves.fetch_add(1);
#endif
	}

private:
	static poolHeader _poolHeader;
	static uint32_t _typeSize;
#ifdef _DEBUG
	static counter _counter;
#endif
};

template<typename _Ty>
uint32_t objectPool<_Ty>::_typeSize = sizeof(_Ty);
