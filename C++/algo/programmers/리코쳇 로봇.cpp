#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
    int ht = board.size(), wd = board[0].size();
    vector<vector<bool>> visited(ht);
    pair<int, int> st, ed;
    for (int i = 0; i < ht; i++) {
        visited[i].resize(wd);
        for (int j = 0; j < wd; j++) {
            if (board[i][j] == 'R')
                st = { i, j };
            if (board[i][j] == 'G')
                ed = { i, j };
        }
    }
    vector<pair<int, int>> pre;
    vector<pair<int, int>> nxt;
    nxt.push_back(st);
    visited[st.first][st.second] = true;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int answer = 0;
    bool trying = true;
    while (!nxt.empty() and trying) {
        pre = nxt;
        answer += 1;
        nxt.clear();
        
        for(auto p:pre) {
            for(int i=0; i<4; i++) {
                int x = p.first;
                int y = p.second;
                while((x + dx[i]) >= 0 and (x + dx[i] != ht) and (y + dy[i] >= 0) and (y + dy[i] != wd) and (board[x + dx[i]][y + dy[i]] != 'D')) {
                    x+=dx[i];
                    y+=dy[i];
                }
                if(!visited[x][y]) {
                    if (x == ed.first and y == ed.second) {
                        trying = false;
                        break;
                    }
                    nxt.push_back({x, y});
                    visited[x][y] = true;
                }   
            }
            if(!trying)
                break;
        }
        if(!trying)
            break;
    }
    if(trying)
        answer = -1;
    return answer;
}