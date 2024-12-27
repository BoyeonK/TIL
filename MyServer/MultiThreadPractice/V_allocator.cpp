#include "V_allocator.h"
#include <Windows.h>

void* V_allocator::Alloc(uint32_t size) {
	const uint64_t pageCount = (size + PAGE_SIZE - 1) / PAGE_SIZE;
	return ::VirtualAlloc(NULL, pageCount * PAGE_SIZE, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
}

void V_allocator::Release(void* ptr) {
	::VirtualFree(ptr, 0, MEM_RELEASE);
}
