#pragma once
#include <queue>
#include "pch.h"
#include "RWLock.h"

using namespace std;

template<typename T>
class CustomQueue {
public:
	RWLock _locks[1];

public:
	void push(T val) {
		WriteLockGuard writeLockGuard_(_locks[0]);
		_Q.push(val);
	}
	T pop() {
		WriteLockGuard writeLockGuard_(_locks[0]);
		T ans = _Q.front();
		_Q.pop();
		return ans;
	}
	T peek() {
		ReadLockGuard readLockGuard_(_locks[0]);
		return _Q.front();
	}
	bool empty() {
		ReadLockGuard readLockGuard_(_locks[0]);
		return _Q.empty();
	}

private:
	queue<T> _Q;
};

void RWLockPractice();

