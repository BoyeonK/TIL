#include "allocPractice.h"
#include "V_allocator.h"
#include <Windows.h>
#include <iostream>
#include <vector>

using namespace std;

void allocPractice() {
	//Windows 환경에서만 동작함
	SYSTEM_INFO info;
	::GetSystemInfo(&info);
	cout << "내 OS의 PageSize는 " << info.dwPageSize << " bytes" << endl;
	cout << "내 OS의 Allocation Graularity는 " << info.dwAllocationGranularity << " bytes" << endl;

	int* allocatedByNew = new int;
	*allocatedByNew = 1;

	int* allocatedByVA = static_cast<int*>(::VirtualAlloc(NULL, sizeof(int), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
	*allocatedByVA = 2;

	int* allocatedByAllocator = static_cast<int*>(V_allocator::Alloc(sizeof(int)));
	*allocatedByAllocator = 3;

	vector<int> va(10);
	vector<int, STLAllocator<int>> vb(10);
	
	cout << *allocatedByNew << endl;
	cout << *allocatedByVA << endl;
	cout << *allocatedByAllocator << endl;

	for (int i = 0; i < 10; i++) {
		va[i] = i;
		vb[i] = 10 - i;
	}
	for (int i = 0; i < 10; i++) {
		cout << va[i] << " " << vb[i] << endl;
	}

	delete allocatedByNew;
	::VirtualFree(allocatedByVA, 0, MEM_RELEASE);
	V_allocator::Release(allocatedByAllocator);
}