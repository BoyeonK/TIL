#pragma once
#include <cstdint>

#define OUT

#define CRASH(cause) {						\
	uint32_t* crash = nullptr;				\
	__analysis_assume(crash != nullptr);	\
	*crash = 0xDEADBEEF;					\
}

#define ASSERT_CRASH(expr) {		\
	if (!(expr)) {					\
		CRASH("ASSERT_CRASH");		\
		__analysis_assume(expr);	\
	}								\
}