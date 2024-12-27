#include <iostream>

using namespace std;

int N, M, x, y, ht, ans = 0;
int arr[500][500];
int dp[500][500];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int dfs(int x, int y) {
    if (x == N - 1 && y == M - 1) {
        return 1;
    }
    else {
        dp[x][y] = 0;
        int X, Y;
        for (int i = 0; i < 4; i++) {
            X = x + dx[i];
            Y = y + dy[i];
            if (X >= 0 && X < N && Y >= 0 && Y<M && arr[x][y]>arr[X][Y]) {
                if (dp[X][Y] == -1) dp[x][y] += dfs(X, Y);
                else dp[x][y] += dp[X][Y];
            }
        }
    }
    return dp[x][y];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        cin >> arr[i][j];
        dp[i][j] = -1;
    }
    cout << dfs(0, 0);
}