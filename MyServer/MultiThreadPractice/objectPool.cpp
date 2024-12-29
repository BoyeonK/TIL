#include "objectPool.h"
#include <windows.h>
#include <malloc.h>
#include "pch.h"

void* objectPool::alloc(uint32_t size) {
	if (size == 0) {
		CRASH("0 byte alloc��û �߻�. �����ΰ� �߸��Ǿ���.");
		return nullptr;
	}
	poolEntry* topEntry = static_cast<poolEntry*>(InterlockedPopEntrySList(&_poolHeader));
	if (topEntry == nullptr) {
		topEntry = static_cast<poolEntry*>(_aligned_malloc(size + sizeof(poolEntry), 16));
	}

	return nullptr;
}
