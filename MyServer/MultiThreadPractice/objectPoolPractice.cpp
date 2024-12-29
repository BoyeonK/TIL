#include "objectPoolPractice.h"
#include "objectPool.h"
#include <windows.h>
#include <malloc.h>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

typedef struct _ITEM {
	SLIST_ENTRY ItemEntry;
	uint32_t Signature;
} ITEM, *PITEM;

void objectPoolPractice() {
	PSLIST_ENTRY pFirstEntry, pListEntry;
	PSLIST_HEADER pListHead;
	ITEM* pit;

	pListHead = static_cast<PSLIST_HEADER>(_aligned_malloc(sizeof(SLIST_HEADER), MEMORY_ALLOCATION_ALIGNMENT));
	if (NULL == pListHead) {
		cout << "Failed to allocate ListHead" << endl;
		return;
	}
	InitializeSListHead(pListHead);

	for (uint32_t i = 0; i < 10; i++) {
		pit = static_cast<PITEM>(_aligned_malloc(sizeof(ITEM), MEMORY_ALLOCATION_ALIGNMENT));
		if (NULL == pit) {
			cout << "Failed to allocate list member" << endl;
			return;
		}
		pit->Signature = i;
		pFirstEntry = InterlockedPushEntrySList(pListHead, &(pit->ItemEntry));
	}

	for (uint32_t i = 10; i > 1; i--) {
		pListEntry = InterlockedPopEntrySList(pListHead);
		if (NULL == pListEntry) {
			cout << "List is empty" << endl;
			return;
		}
		pit = reinterpret_cast<PITEM>(pListEntry);
		cout << "Signature is " << pit->Signature << endl;

		_aligned_free(pListEntry);
	}

	pListEntry = InterlockedFlushSList(pListHead);
	pFirstEntry = InterlockedPopEntrySList(pListHead);
	if (pFirstEntry != NULL) {
		cout << "List isn't Empty" << endl;
		return;
	}
	_aligned_free(pListHead);

	vector<int*> pns;

	for (int i = 0; i < 10; i++) {
		int* pn = objectPool<int>::alloc();
		pns.push_back(pn);
	}

	return;
}