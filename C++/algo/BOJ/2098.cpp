#include <iostream>
#include <memory.h>

using namespace std;

const int MXM = 16000001;
int dp[16][1<<16];
int price[16][16];
int N;

int dfs(int now, int visited) {
	if (visited == ((1 << N) - 1)) {
		if (price[now][0])
			return price[now][0];
		return MXM;
	}
	int* pN = &dp[now][visited];
	if (*pN != -1)
		return *pN;
	*pN = MXM;
	for (int i = 0; i < N; i++) {
		int vb = 1 << i, pr = price[now][i];
		if (!(visited & vb) and pr) 
			*pN = min(*pN, dfs(i, visited | vb) + pr);		
	}
	return *pN;
}

int main() {
	cin >> N;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> price[i][j];
	cout << dfs(0, 1);
}