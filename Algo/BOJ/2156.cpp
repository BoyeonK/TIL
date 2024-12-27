#include <iostream>

using namespace std;

int bn(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int* DP = new int[N];
	int* gw = new int[N];
	for (int i = 0; i < N; i++) cin >> gw[i];
	DP[0] = gw[0];
	if (N > 1) DP[1] = gw[0] + gw[1];
	if (N > 2) DP[2] = bn(gw[1] + gw[2], bn(gw[0] + gw[1], gw[0] + gw[2]));
	if (N > 3) {
		for (int i = 3; i < N; i++) DP[i] = bn(DP[i - 1], bn(DP[i - 2], DP[i - 3] + gw[i - 1]) + gw[i]);
	}
	cout << DP[N - 1];
}