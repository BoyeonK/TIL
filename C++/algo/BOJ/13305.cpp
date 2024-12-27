#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, pcst, ncst;
	long long tc=0, tl=0;
	cin >> N;
	int* lnt = new int[N-1] {};
	for (int i = 0; i < N - 1; i++) cin >> lnt[i];
	cin >> pcst;
	for (int i = 0; i < N - 1; i++) {
		cin >> ncst;
		tl += lnt[i];
		if (pcst > ncst) {
			tc += tl * pcst;
			tl = 0;
			pcst = ncst;
		}
	}
	if (tl) tc += tl * pcst;
	cout << tc;
}