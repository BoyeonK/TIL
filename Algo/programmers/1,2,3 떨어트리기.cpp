#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> grp;
vector<int> visited;
int N;

int findLeaf(int nodenum) {
    if (grp[nodenum].size() == 0)
        return nodenum;
    int nxt = grp[nodenum][visited[nodenum] % grp[nodenum].size()];
    visited[nodenum] += 1;
    return findLeaf(nxt);
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer;

    N = edges.size() + 1;
    grp.resize(N);
    visited.resize(N);
    for (auto& edge : edges)
        grp[edge[0] - 1].push_back(edge[1] - 1);
    for (auto& edge : grp)
        sort(edge.begin(), edge.end());
    vector<int> count(N);
    vector<bool> canMakeLeaf(N);
    queue<int> Q;
    int leafs = 0;
    int canMakeLeafNum = 0;
    bool success = true;
    for (int t : target)
        if (t)
            leafs += 1;
    //cout << leafs << endl;
    while (true) {
        int now = findLeaf(0);

        //cout << now << endl;

        count[now] += 1;
        Q.push(now);
        if (count[now] > target[now]) {
            success = false;
            break;
        }
        if (count[now] * 3 >= target[now] and !canMakeLeaf[now]) {
            canMakeLeaf[now] = true;
            canMakeLeafNum += 1;
        }
        if (canMakeLeafNum == leafs)
            break;
    }
    
    if (success) {
        vector<vector<int>> lines(N);
        for (int i = 0; i < N; i++) {
            if (target[i]) {
                vector<int> line(count[i], 1);
                int last = target[i] - count[i];
                int idx = count[i] - 1;
                while (last > 0) {
                    if(last >= 2) {
                        line[idx] += 2;
                        last -= 2;
                    }
                    else {
                        line[idx] += 1;
                        last -= 1;
                    }
                    idx--;
                }
                lines[i] = line;
            }
        }
        vector<int> nodeSeq(N);
        while (!Q.empty()) {
            int top = Q.front();
            answer.push_back(lines[top][nodeSeq[top]]);
            nodeSeq[top]++;
            Q.pop();
        }
    }

    else 
        answer.push_back(-1);

    return answer;
}