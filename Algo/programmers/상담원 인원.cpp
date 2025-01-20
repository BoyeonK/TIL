#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> s(6);
vector<vector<int>> e(6);

int cal(int type, int n) {
    int seq = 0;
    int N = s[type].size();
    int waiting = 0, dif;
    priority_queue<int> endtime;
    endtime.push(-2147483647);
    for (int i = 0; i < N; i++) {
        while (-endtime.top() <= s[type][i]) {
            seq--;
            endtime.pop();
        }
        if (seq < n) {
            seq++;
            endtime.push(-(s[type][i] + e[type][i]));
        }
        else {
            dif = -endtime.top() - s[type][i];
            waiting += dif;
            endtime.pop();
            endtime.push(-(s[type][i] + e[type][i] + dif));
        }
    }
    return waiting;
}

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 0;
    for (auto& v : reqs) {
        s[v[2]].push_back(v[0]);
        e[v[2]].push_back(v[1]);
    }
    vector<int> seq(6);
    vector<int> progress(6);
    vector<int> waitings(6);
    for (int i = 1; i <= k; i++) {
        seq[i] = 2;
        waitings[i] = cal(i, 1);
        progress[i] = waitings[i] - cal(i, 2);
    }

    int pg = n - k;
    int mxm, idx = 1;
    for (int n = 0; n < pg; n++) {
        mxm = 0;
        idx = 1;
        for (int i = 1; i <= k; i++) {
            if (progress[i] > mxm) {
                idx = i;
                mxm = progress[i];
            }
        }
        waitings[idx] = cal(idx, seq[idx]);
        seq[idx]++;
        progress[idx] = waitings[idx] - cal(idx, seq[idx]);
    }
    for (auto wt : waitings) {
        answer += wt;
    }
    return answer;
}