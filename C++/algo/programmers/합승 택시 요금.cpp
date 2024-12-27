#include <string>
#include <vector>
#include <queue>

using namespace std;

const int MXM = 20000001;
vector<vector<pair<int, int>>> grp;

vector<int> dijk(int st, int n) {
    vector<bool> visited(n+1);
    vector<int> ttdst(n+1, MXM);
    priority_queue<pair<int, int>> pq;
    pq.push({0, st});
    ttdst[st] = 0;
    int now, nxt, dst, nxtdst;
    while(!pq.empty()) {
        now = pq.top().second;
        dst = -pq.top().first;
        pq.pop();
        if(visited[now])
            continue;
        visited[now] = true;
        for(auto p:grp[now]) {
            nxt=p.first;
            nxtdst=dst+p.second;
            if(ttdst[nxt]>nxtdst){
                ttdst[nxt] = nxtdst;
                pq.push({-nxtdst, nxt});
            }
        }
    }
    return ttdst;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    grp.resize(n+1);
    for(auto f:fares) {
        int x = f[0], y = f[1], p = f[2];
        grp[x].push_back({y, p});
        grp[y].push_back({x, p});
    }
    vector<int> sv = dijk(s, n);
    vector<int> av = dijk(a, n);
    vector<int> bv = dijk(b, n);
    int mnm = MXM, dp;
    for (int i=1; i<=n; i++) {
        dp = sv[i] + av[i] + bv[i];
        mnm = min(dp, mnm);
    }
    return mnm;
}