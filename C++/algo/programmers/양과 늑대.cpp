#include <string>
#include <vector>

using namespace std;

vector<vector<int>> grp(17);
vector<bool> visited(17);
vector<int> newInfo;
int mnm = 0;

void dfs(int nm, int s, int w, vector<int> linked) {
    if (newInfo[nm])
        w += 1;
    else
        s += 1;
    if (w >= s)
        return;
    else if (s > mnm)
        mnm = s;
    for (auto l : grp[nm])
        linked.push_back(l);
    for (auto l : linked) {
        if (!visited[l]) {
            visited[l] = true;
            dfs(l, s, w, linked);
            visited[l] = false;
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    newInfo = info;
    for (auto l : edges)
        grp[l[0]].push_back(l[1]);    
    dfs(0, 0, 0, {});
    return mnm;
}