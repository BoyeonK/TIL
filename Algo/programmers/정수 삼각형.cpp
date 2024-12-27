#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int n = triangle.size();
    vector<vector<int>> dp;
    dp = triangle;
    int a, b;
    for (int depth = 1; depth < n; depth++) {
        for (int idx = 0; idx <= depth; idx++) {
            a = (idx == 0) ? 0 : dp[depth - 1][idx - 1];
            b = (idx == depth) ? 0 : dp[depth - 1][idx];
            dp[depth][idx] = max(a, b) + triangle[depth][idx];
        }
    }
    int mxm = 0;
    for (int i = 0; i < n; i++)
        if (dp[n - 1][i] > mxm) mxm = dp[n - 1][i];
    return mxm;
}