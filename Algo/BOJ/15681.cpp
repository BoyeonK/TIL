#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> grp;
vector<bool> visited;
vector<int> sons;

int dfs(int N) {
    visited[N] = true;
    for (int& e : grp[N]) 
        if (!visited[e])
            sons[N] += dfs(e);
    return sons[N];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, R, Q, s, e;
    cin >> N >> R >> Q;
    grp.resize(N + 1);
    visited.resize(N + 1);
    sons.resize(N + 1);
    fill(sons.begin(), sons.end(), 1);
    for (int i = 1; i < N; i++) {
        cin >> s >> e;
        grp[s].push_back(e);
        grp[e].push_back(s);
    }
    dfs(R);
    while (Q--) {
        cin >> s;
        cout << sons[s] << '\n';
    }
}