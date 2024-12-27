#include <iostream>
#include <deque>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, cnt, inp, tt = 0, mxm;
	cin >> N >> cnt;
	N -= cnt;
	deque<int> arr;
	while (cnt--) {
		cin >> inp;
		tt += inp;
		arr.push_back(inp);
	}
	mxm = tt;
	while (N--) {
		cin >> inp;
		tt += (inp - arr.front());
		arr.push_back(inp);
		arr.pop_front();
		if (tt > mxm) mxm = tt;
	}
	cout << mxm;
}