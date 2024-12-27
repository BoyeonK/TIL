#pragma once
#include <thread>
#include <future>
#include <vector>
#include <functional>

using namespace std;

int calculate(int startnum = 0) {
	int ans = startnum;
	for (int i = 0; i < 10'000; i++) ans += 1;
	return ans;
}

void promiseCal(promise<int>& pr, int startnum = 0) {
	int ans = startnum;
	for (int i = 0; i < 10'000; i++) ans += 1;
	pr.set_value(ans);
}

class futurePractice {
public:
	template<typename... Args>
	void CalByAsync(function<int(Args...)>& func, Args... args) {
		_fts.push_back(async(launch::async, func, args...));
	}

	template<typename... Args>
	void CalByPromise(function<int(Args...)>& func, Args... args) {
		promise<int> pr;
		_fts.push_back(pr.get_future());
		thread thr(, )

	}

	template<typename... Args>
	void CalByPackagedTask(function<int(Args...)>& func, Args... args) {

	}

private:
	promise<int> _pr;
	vector<future<int>> _fts;
};

