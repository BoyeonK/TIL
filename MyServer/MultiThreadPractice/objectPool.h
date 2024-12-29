#pragma once
#include <cstdint>
#include <windows.h>
#include <malloc.h>
#include "pch.h"

struct poolEntry : public SLIST_ENTRY {
	uint32_t size;
};

template<typename _Ty>
class objectPool {
public:
	static void* alloc() {
		poolEntry* pTopEntry = static_cast<poolEntry*>(::InterlockedPopEntrySList(&_poolHeader));
		if (pTopEntry == nullptr) {
			pTopEntry = static_cast<poolEntry*>(_aligned_malloc(sizeof(poolEntry) + _typeSize, 16));
		}
	}
private:
	alignas(16) static SLIST_HEADER _poolHeader;
	static uint32_t _typeSize;
};

template<typename _Ty>
uint32_t objectPool<_Ty>::_typeSize = sizeof(_Ty);

template<typename _Ty, typename... Args>
_Ty* newPool(Args&&... args) {

}
