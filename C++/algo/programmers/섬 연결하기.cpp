#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    vector<vector<pair<int, int>>> grp(n);
    vector<bool> visited(n);
    for (auto& c : costs) {
        grp[c[0]].push_back({ c[2], c[1] });
        grp[c[1]].push_back({ c[2], c[0] });
    }
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, 0 });
    int iter = 0, cst, now, nxt, ttcst = 0;
    while (iter != n) {
        now = pq.top().second;
        cst = -pq.top().first;
        pq.pop();
        if (visited[now]) continue;
        visited[now] = true;
        ttcst += cst;
        iter++;
        for (auto& l : grp[now]) {
            nxt = l.second;
            if (!visited[nxt])
                pq.push({ -l.first, nxt });
        }
    }
    return ttcst;
}