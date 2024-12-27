#include <iostream>
#include <memory.h>

using namespace std;

const int MXM = 10000000;
int W[3][1000];
int dp[3][3][1000];
int N, scr;

int dfs(int cr, int seq) {
	if (seq == N)
		return 0;
	int* pDp = &dp[scr][cr][seq];
	if (*pDp != -1)
		return *pDp;
	*pDp = MXM;
	for (int i = 0; i < 3; i++) {
		if (cr == i)
			continue;
		if ((seq + 2) == N and i == scr)
			continue;
		*pDp = min(*pDp, dfs(i, seq + 1) + W[cr][seq]);
	}
	return *pDp;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> W[0][i] >> W[1][i] >> W[2][i];
	int mnm = MXM;
	for (int i = 0; i < 3; i++) {
		scr = i;
		if (mnm > dfs(i, 0))
			mnm = dfs(i, 0);
	}
	cout << mnm;
}