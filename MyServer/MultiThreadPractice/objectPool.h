#pragma once
#include <cstdint>

struct poolEntry : public SLIST_ENTRY {
	uint32_t size;
};

class objectPool {
private:
	alignas(16) static SLIST_HEADER poolHeader;
};

template<typename _Ty, typename... Args>
_Ty* newPool(Args&&... args) {

}