#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<stack<pair<int,int>>> sortByY;
vector<int> post;
vector<int> last;

void dfs(int my_x, int my_num, int level, int lLim, int rLim) {
    post.push_back(my_num);
    if (sortByY.size()-1 > level) {
        while (!sortByY[level + 1].empty()) {
            int nxt_x = sortByY[level + 1].top().first;
            int nxt_num = sortByY[level + 1].top().second;
            if (nxt_x < my_x) {
                sortByY[level + 1].pop();
                dfs(nxt_x, nxt_num, level + 1, lLim, my_x);
            }
            else if (nxt_x < rLim) {
                sortByY[level + 1].pop();
                dfs(nxt_x, nxt_num, level + 1, lLim, rLim);
            }
            else
                break;
        }
    }
    last.push_back(my_num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> NI;
    int num = 0, x, y;
    for (auto l : nodeinfo) {
        x = l[0];
        y = l[1];
        NI.push_back({ y, x, ++num });
    }
    sort(NI.rbegin(), NI.rend());
    int idx = -1, level = 100001;
    for (int i = 0; i < NI.size(); i++) {
        if (level != NI[i][0]) {
            sortByY.push_back({});
            level = NI[i][0];
            idx++;
        }
        sortByY[idx].push({ NI[i][1], NI[i][2] });
    }
    dfs(sortByY[0].top().first, sortByY[0].top().second, 0, 0, 100001);
    vector<vector<int>> answer;
    answer.push_back(post);
    answer.push_back(last);
    return answer;
}