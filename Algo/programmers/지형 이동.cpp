#include <string>
#include <vector>
#include <tuple>
#include<queue>

using namespace std;

int solution(vector<vector<int>> land, int height) {
    int answer = 0, mxi = land.size(), mxj = land[0].size();
    int di[4] = { 0, 1, 0, -1 };
    int dj[4] = { 1, 0, -1, 0 };
    int ladder, i, j, ni, nj, nxtdst, seq=0;
    priority_queue<tuple<int, int, int>>pQ;
    vector<vector<bool>>visited(mxi, vector<bool>(mxj));
    vector<vector<int>>dst(mxi, vector<int>(mxj, 2147483647));
    pQ.push(make_tuple(0, 0, 0));
    while (!pQ.empty()) {
        tie(ladder, i, j) = pQ.top();
        ladder = -ladder;
        pQ.pop();
        if (visited[i][j])
            continue;
        visited[i][j] = true;
        if (ladder > height) {
            answer += ladder;
        }
        for (int k = 0; k < 4; k++) {
            ni = i + di[k];
            nj = j + dj[k];
            if (0 <= ni and ni < mxi and 0 <= nj and nj < mxj) {
                nxtdst = abs(land[ni][nj] - land[i][j]);
                if (dst[ni][nj]>nxtdst and !visited[ni][nj]) {
                    pQ.push(make_tuple(-nxtdst, ni, nj));
                    dst[ni][nj] = nxtdst;
                }
            }
        }
    }
    return answer;
}