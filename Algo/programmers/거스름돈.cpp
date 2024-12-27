#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    vector<int> dp(n + 1);
    for (int c : money) {
        if (c > n)
            continue;
        int idx = 1;
        dp[c] += 1;
        while (idx + c <= n) {
            if (dp[idx])
                dp[idx + c] += dp[idx];
            idx++;
        }
    }
    return dp[n];
}