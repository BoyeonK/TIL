#include <string>
#include <vector>

using namespace std;

vector<vector<int>>dp;
vector<int> num;
int dfs(int l, int r) {
    if (dp[l][r] != -1)
        return dp[l][r];
    dp[l][r] = 2147483647;
    for (int i = l + 1; i < r; i++)
        dp[l][r] = min(dp[l][r], (dfs(l, i) + dfs(i, r) + num[l] * num[i] * num[r]));
    return dp[l][r];
}

int solution(vector<vector<int>> matrix_sizes) {
    int n = matrix_sizes.size();
    for (int i = 0; i < n; i++) {
        vector<int> l(n + 1, -1);
        dp.push_back(l);
        dp[i][i + 1] = 0;
    }
    num.push_back(matrix_sizes[0][0]);
    num.push_back(matrix_sizes[0][1]);
    for (int i = 1; i < n; i++)
        num.push_back(matrix_sizes[i][1]);
    int answer = dfs(0, n);
    return answer;
}