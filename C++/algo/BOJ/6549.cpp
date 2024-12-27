#include <iostream>
#include <deque>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, inp, popi;
	long long ar, mxm = 0;
	deque<pair<int, long long>> Q;
	pair<int, int> sqr;
	cin >> N;
	while (N) {
		for (int i = 0; i < N; i++) {
			cin >> inp;
			popi = i;
			while (!Q.empty() && Q.front().second > inp) {
				ar = (i - (Q.front().first)) * Q.front().second;
				if (ar > mxm) mxm = ar;
				popi = Q.front().first;
				Q.pop_front();
			}
			Q.push_front(make_pair(popi, inp));
		}
		while (!Q.empty()) {
			ar = (N - (Q.front().first)) * Q.front().second;
			if (ar > mxm) mxm = ar;
			Q.pop_front();
		}
		cout << mxm << '\n';
		mxm = 0;
		cin >> N;
	}
}