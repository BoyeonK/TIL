#include <iostream>
#include <memory.h>

using namespace std;

const int MXM = 1048576;
int w[20][20];
int dp[MXM];
int N, pN;

int dfs(int seq, int visited) {
	if (dp[visited] != -1) 
		return dp[visited];
	
	dp[visited] = MXM;
	for (int i = 0; i < N; i++) {
		int vb = 1 << i;
		if (visited & vb)
			continue;
		dp[visited] = min(dp[visited], dfs(seq + 1, visited | vb) + w[seq][i]);
	}
	return dp[visited];
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> N;
	pN = 1 << N;
	dp[pN - 1] = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> w[i][j];
	cout << dfs(0, 0);
}