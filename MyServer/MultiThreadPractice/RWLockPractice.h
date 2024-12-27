#pragma once
#include <queue>
#include "pch.h"
#include "RWLock.h"

using namespace std;

template<typename T>
class CustomQueue {
public:
	USE_RWLOCK

public:
	void push(T val) {
		WRITE_RWLOCK
		_Q.push(val);
	}
	T pop() {
		WRITE_RWLOCK
		T ans = _Q.front();
		_Q.pop();
		return ans;
	}
	T peek() {
		READ_RWLOCK
		return _Q.front();
	}
	bool empty() {
		READ_RWLOCK
		return _Q.empty();
	}

private:
	queue<T> _Q;
};

void RWLockPractice();

