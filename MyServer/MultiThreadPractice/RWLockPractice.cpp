#include "RWLockPractice.h"
#include <iostream>
#include <thread>
#include "TLSvariables.h"

CustomQueue<int> MyQ;
int Tid = 1;

void AutoPop() {
	MyThreadID = Tid++;
	int p;
	for (int i = 0; i < 100; i++) {
		p = MyQ.pop();
		cout << MyThreadID << " " << p << endl;
	}
}

void RWLockPractice() {
	for (int i = 0; i < 10'000; i++) {
		MyQ.push(i);
	}

	thread t1(AutoPop);
	thread t2(AutoPop);
	thread t3(AutoPop);

	t1.join();
	t2.join();
	t3.join();
}
