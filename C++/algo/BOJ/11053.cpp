#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, mxm=0, ans;
	cin >> N;
	int* arr = new int[N] {};
	int* dp = new int[N] {};
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		for (int j = 0; j < i; j++) if (arr[i] > arr[j] && dp[j] > mxm) mxm = dp[j];
		dp[i] = mxm + 1;
		mxm = 0;
	}
	for (int i = 0; i < N; i++) if (dp[i] > mxm) mxm = dp[i];
	cout << mxm;
}