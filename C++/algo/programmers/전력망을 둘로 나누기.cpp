#include <string>
#include <vector>

using namespace std;

vector<vector<int>> grp(101);
vector<bool> visited(101);
int mnm=100, N;
int dfs(int l) {
    visited[l] = true;
    int num=1, dif;
    for(int i:grp[l])
        if(!visited[i])
            num+=dfs(i);
    dif = abs(N-2*num);
    if(mnm>dif)
        mnm=dif;
    return num;
}

int solution(int n, vector<vector<int>> wires) {
    for(auto w:wires) {
        grp[w[0]].push_back(w[1]);
        grp[w[1]].push_back(w[0]);
    }
    N = n;
    dfs(1);
    int answer = mnm;
    return answer;
}