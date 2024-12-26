#include <iostream>
#include <thread>
#include <future>

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

int main() {
	thread t1(calculate, 1);

	future<int> ft1 = async(launch::async, calculate, 1);

	promise<int> pr;
	future<int> ft2 = pr.get_future();
	thread t2(promiseCal, ref(pr), 2);

	packaged_task<int(int)> task(calculate);
	future<int> ft3 = task.get_future();
	thread t3(move(task), 3);
	
	int ans1 = ft1.get();
	int ans2 = ft2.get();
	int ans3 = ft3.get();

	t1.join();
	t2.join();
	t3.join();

	cout << ans1 << endl;
	cout << ans2 << endl;
	cout << ans3 << endl;
}