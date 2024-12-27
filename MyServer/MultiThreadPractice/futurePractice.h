#pragma once
#include <thread>
#include <future>

using namespace std;

int calculate(int startnum);

void promiseCal(promise<int>& pr, int startnum);

void FuturePractice();