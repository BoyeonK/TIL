#include <string>
#include <vector>

using namespace std;

vector<vector<int>> bl;
vector<bool> visited(1024);
int answer = 0;

void dfs(int idx, int bits) {
    if (idx == bl.size()) {
        if (!visited[bits]) {
            visited[bits] = true;
            answer += 1;
        }
    }
    else {
        if (bl[idx].empty())
            dfs(idx + 1, bits);
        else {
            for (int i : bl[idx]) {
                int b = (1 << i);
                if (!(bits & b)) 
                    dfs(idx + 1, bits | b);
            }
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int us = user_id.size();
    int bs = banned_id.size();
    bl.resize(bs);
    for (int i = 0; i < us; i++) {
        string uid = user_id[i];
        int l = uid.size();
        for (int j = 0; j < bs; j++) {
            string bid = banned_id[j];
            int m = bid.size();
            if (l != m)
                continue;
            int idx = 0;
            while (idx < m and uid[idx] == bid[idx] or bid[idx] == '*')
                idx++;
            if (idx == m)
                bl[j].push_back(i);
        }
    }
    answer = 0;
    dfs(0, 0);
    return answer;
}