#include <string>
#include <vector>
#include<queue>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<vector<pair<int, int>>>grp(n + 1);
    vector<pair<int, int>>dp(n + 1, { 0, 2147483647 });
    vector<bool> isSummit(n + 1);
    vector<bool> isGate(n + 1);
    sort(summits.begin(), summits.end());
    for (int summit : summits)
        isSummit[summit] = true;
    for (int gate : gates)
        isGate[gate] = true;
    for (auto p : paths) {
        grp[p[0]].push_back({ p[1], p[2] });
        grp[p[1]].push_back({ p[0], p[2] });
    }
    queue<pair<int, int>> Q;

    int now, intensity, nxt, nxtIntensity;
    for (int summit : summits) {
        Q.push({ summit,0 });
        while (!Q.empty()) {
            now = Q.front().first;
            intensity = Q.front().second;
            Q.pop();
            if (isGate[now] == true)
                continue;
            for (auto& e : grp[now]) {
                nxt = e.first;
                nxtIntensity = max(intensity, e.second);
                if (dp[nxt].second > nxtIntensity and isSummit[nxt]==false) {
                    dp[nxt] = { summit, nxtIntensity };
                    Q.push({ nxt, nxtIntensity });
                }
            }
        }
    }
    int mnm = 2147483647, a0, a1;
    for (int g : gates) {
        if (mnm >= dp[g].second) {
            if (mnm == dp[g].second) {
                if (dp[g].first < a0) {
                    a0 = dp[g].first;
                }
            }
            else {
                mnm = dp[g].second;
                a0 = dp[g].first;
                a1 = mnm;
            }
        }
    }

    vector<int>answer{a0, a1};

    return answer;
}