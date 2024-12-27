#pragma once
#include <cstdint>

class V_allocator {
	enum {
		PAGE_SIZE = 0x1000,
	};

public:
	static void*	Alloc(uint32_t size);
	static void		Release(void* ptr);
};

