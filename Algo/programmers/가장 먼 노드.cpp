#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> grp(n+1);
    for(auto e:edge){
        grp[e[0]].push_back(e[1]);
        grp[e[1]].push_back(e[0]);
    }
    vector<bool> visited(n+1);
    vector<int> pre, nxt;
    nxt.push_back(1);
    visited[1] = true;
    while(!nxt.empty()) {
        pre = nxt;
        nxt.clear();
        for(int i:pre) {
            for(int j:grp[i]) {
                if(!visited[j]) {
                    nxt.push_back(j);
                    visited[j] = true;
                }
            }
        }
    }
    int answer = pre.size();
    return answer;
}