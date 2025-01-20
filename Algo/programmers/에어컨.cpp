#include <string>
#include <vector>
#include <memory.h>

using namespace std;

int tp, l, r, ON, OFF, N, mnm = 2147483647;
vector<int> ob;

int dp[1001][1001];

void bfs(int t) {
    if (t == N) {
        return;
    }
    for (int i = 0; i <= 1000; i++) {
        if (ob[t] == 1) {
            if (i<l or i>r)
                dp[t][i] = -1;
        }
        if (dp[t][i] == -1)
            continue;
        if (i > tp) {
            dp[t + 1][i + 1] = (dp[t + 1][i + 1] == -1) ? dp[t][i] + ON : min(dp[t + 1][i + 1], dp[t][i] + ON);
            dp[t + 1][i] = (dp[t + 1][i] == -1) ? dp[t][i] + OFF : min(dp[t + 1][i], dp[t][i] + OFF);
            dp[t + 1][i - 1] = (dp[t + 1][i - 1]==-1) ? dp[t][i] : min(dp[t + 1][i - 1], dp[t][i]);
        }
        else if (i == tp) {
            dp[t + 1][i + 1] = (dp[t + 1][i + 1] == -1) ? dp[t][i] + ON : min(dp[t + 1][i + 1], dp[t][i] + ON);
            dp[t + 1][i] = (dp[t + 1][i]==-1) ? dp[t][i] : min(dp[t + 1][i], dp[t][i]);
            dp[t + 1][i - 1] = (dp[t + 1][i - 1] == -1) ? dp[t][i] + ON : min(dp[t + 1][i - 1], dp[t][i] + ON);
        }
        else {
            dp[t + 1][i + 1] = (dp[t + 1][i + 1] == -1) ? dp[t][i] : min(dp[t + 1][i + 1], dp[t][i]);
            dp[t + 1][i] = (dp[t + 1][i] == -1) ? dp[t][i] + OFF : min(dp[t + 1][i], dp[t][i] + OFF);
            dp[t + 1][i - 1] = (dp[t + 1][i - 1] == -1) ? dp[t][i] + ON : min(dp[t + 1][i - 1], dp[t][i] + ON);
        }
    }
    bfs(t + 1);
}

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    memset(dp, -1, sizeof(dp));
    tp = temperature + 500;
    l = t1 + 500;
    r = t2 + 500;
    ON = a;
    OFF = b;
    ob = onboard;
    N = onboard.size();
    dp[0][tp] = 0;
    bfs(0);
    int last = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (onboard[i] == 1) {
            last = i;
            break;
        }
    }
    for (int i = 0; i <= 1000; i++) {
        if (dp[last][i] == -1)
            continue;
        if (dp[last][i] < mnm)
            mnm = dp[last][i];
    }
    return mnm;
}