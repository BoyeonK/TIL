#include "pch.h"
#include <iostream>

using namespace std;

int main() {
	cout << "I'm Client" << endl;
#ifdef PROTOBUF_NAMESPACE_OPEN
	std::cout << "PROTOBUF_NAMESPACE_OPEN is defined." << std::endl;
#else
	std::cout << "PROTOBUF_NAMESPACE_OPEN is NOT defined." << std::endl;
#endif
}