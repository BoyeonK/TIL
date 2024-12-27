#include "allocPractice.h"
#include <Windows.h>
#include <iostream>

using namespace std;

void allocPractice() {
	//Windows 환경에서만 동작함
	SYSTEM_INFO info;
	::GetSystemInfo(&info);
	cout << "내 OS의 PageSize는 " << info.dwPageSize << " bytes" << endl;
	cout << "내 OS의 Allocation Graularity는 " << info.dwAllocationGranularity << " bytes" << endl;

	int* allocatedByNew = new int;
	*allocatedByNew = 1;

	int* allocatedByVA = (int*)::VirtualAlloc(NULL, sizeof(int), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	*allocatedByVA = 2;

	cout << *allocatedByNew << endl;
	cout << *allocatedByVA << endl;

	delete allocatedByNew;
	::VirtualFree(allocatedByVA, 0, MEM_RELEASE);
}