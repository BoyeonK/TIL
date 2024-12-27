#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	long long N, M, inp, md = 0, nw, tt = 0;
	cin >> N >> M;
	long long* cnt = new long long int[M] {1,};
	while (N--) {
		cin >> inp;
		nw = (inp + md) % M;
		md = nw;
		cnt[nw] += 1;
	}
	for (int i = 0; i < M; i++) {
		if (cnt[i] > 1) tt += (cnt[i] * cnt[i] - cnt[i]) / 2;
	}
	cout << tt;
}