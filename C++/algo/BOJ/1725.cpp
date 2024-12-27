#include <iostream>
#include <deque>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, ht, sqr, si, mxm = 0;
	deque<pair<int, int>>stk;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ht;
		si = i;
		while (!stk.empty() && stk.back().second > ht) {
			si = stk.back().first;
			sqr = (i - stk.back().first) * stk.back().second;
			if (sqr > mxm) mxm = sqr;
			stk.pop_back();
		}
		stk.push_back({ si, ht });
	}
	while (!stk.empty()) {
		sqr = (N - stk.back().first) * stk.back().second;
		if (sqr > mxm) mxm = sqr;
		stk.pop_back();
	}
	cout << mxm;
}