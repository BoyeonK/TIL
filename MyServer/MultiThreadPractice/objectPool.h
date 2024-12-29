#pragma once
#include <cstdint>
#include <windows.h>
#include <malloc.h>
#include <atomic>

using namespace std;

struct poolEntry : public SLIST_ENTRY {
	uint32_t size;
};

#ifdef _DEBUG
class counter {
private:
	atomic<uint32_t> _uses = 0;
	atomic<uint32_t> _reserves = 0;
};
#endif

template<typename _Ty>
class objectPool {
public:
	static poolEntry* popEntry() {
		poolEntry* pEntry = static_cast<poolEntry*>(::InterlockedPopEntrySList(&_poolHeader));
		if (pEntry == nullptr) {
			pEntry = static_cast<poolEntry*>(_aligned_malloc(sizeof(poolEntry) + _typeSize, 16));
		}
		return pEntry;
	}

private:
	alignas(16) static SLIST_HEADER _poolHeader;
	static uint32_t _typeSize;
#ifdef _DEBUG
	static counter;
#endif
};

template<typename _Ty>
uint32_t objectPool<_Ty>::_typeSize = sizeof(_Ty);

template<typename _Ty, typename... Args>
_Ty* newPool(Args&&... args) {

}
