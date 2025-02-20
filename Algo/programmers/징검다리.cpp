#include <string>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    vector<int>distances;
    
    distances.push_back(rocks[0]);
    for (int i = 0; i < rocks.size() - 1; i++) {
        distances.push_back(rocks[i + 1] - rocks[i]);
    }
    distances.push_back(distance - rocks[rocks.size() - 1]);
    vector<bool>isRock(distances.size(), true);
    
    priority_queue<pair<int, int>>pQ;
    for (int i = 0; i < distances.size(); i++) {
        pQ.push({ -distances[i], i });
    }
    int seq = 0, idx, dst, ridx, lidx, selectedidx, nxtdst;
    while (!pQ.empty()) {
        idx = pQ.top().second;
        dst = -pQ.top().first;
        pQ.pop();
        if (!isRock[idx])
            continue;
        ridx = idx + 1;
        lidx = idx - 1;
        while (true) {
            if (ridx == distances.size()) {
                ridx = -1;
                break;
            }
            if (isRock[ridx])
                break;
            ridx++;
        }
        while (true) {
            if (lidx == -1)
                break;
            if (isRock[lidx])
                break;
            lidx--;
        }
        if (ridx == -1)
            selectedidx = lidx;
        else if (lidx == -1)
            selectedidx = ridx;
        else {
            selectedidx = (distances[lidx] < distances[ridx]) ? lidx : ridx;
        }
        isRock[selectedidx] = false;
        nxtdst = dst + distances[selectedidx];
        distances[idx] = nxtdst;
        pQ.push({ -nxtdst, idx });
        seq++;
        if (seq == n)
            break;
    }
    while (true) {
        if (isRock[pQ.top().second])
            break;
        pQ.pop();
    }
    answer = -pQ.top().first;
    return answer;
}