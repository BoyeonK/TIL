#include <iostream>
#include <memory.h>

using namespace std;
typedef long long ll;

const ll nmr = 1000000003;
ll dp[1001][1001];

ll dfs(int X, int Y) {
	if ((2 * Y - 1) > X)
		return 0;
	if (dp[X][Y] != -1)
		return dp[X][Y];
	dp[X][Y] = (dfs(X - 1, Y) + dfs(X - 2, Y - 1)) % nmr;
	return dp[X][Y];
}

int main() {
	memset(dp, -1, sizeof(dp));
	int N, K;
	cin >> N >> K;
	for (int i = 0; i <= N; i++) {
		dp[i][1] = i;
		dp[i][0] = 1;
		if (i % 2)
			dp[i][(i / 2) + 1] = 1;
	}
	ll ans = (dfs(N - 1, K) + dfs(N - 3, K - 1)) % nmr;
	cout << ans;
}