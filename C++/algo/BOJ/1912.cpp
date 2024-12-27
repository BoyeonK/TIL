#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, mxm, seq, nm;
	cin >> N;
	cin >> seq;
	mxm = seq;
	if (seq < 0) seq = 0;
	for (int i = 1; i < N; i++) {
		cin >> nm;
		if (seq + nm > mxm) mxm = seq + nm;
		if (seq + nm > 0) seq += nm;
		else seq = 0;
	}
	cout << mxm;
}