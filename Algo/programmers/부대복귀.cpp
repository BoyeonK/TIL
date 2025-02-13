#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> turn(n + 1, -1);
    vector<bool>visited(n + 1);
    queue<int> Q;
    vector<vector<int>>grp(n + 1);
    for (auto& l : roads) {
        grp[l[0]].push_back(l[1]);
        grp[l[1]].push_back(l[0]);
    }


    Q.push(destination);

    int seq = 0;
    while (!Q.empty()) {
        int now;
        queue<int> nxtQ;
        while (!Q.empty()) {
            now = Q.front();
            Q.pop();
            if (visited[now])
                continue;
            visited[now] = true;
            turn[now] = seq;

            for (int nxt : grp[now]) {
                if (visited[nxt] == false) {
                    nxtQ.push(nxt);
                }
            }
        }
        Q = nxtQ;
        seq++;
    }
    vector<int> sex;
    for (auto a : sources) {
        sex.push_back(turn[a]);
    }

    return sex;
}