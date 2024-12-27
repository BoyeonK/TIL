#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int tm, tt=0, idx=1, n=jobs.size();
    priority_queue<pair<int, int>> pq;
    sort(jobs.begin(), jobs.end());
    pq.push({-jobs[0][1], jobs[0][0]});
    tm = jobs[0][0];
    while(!pq.empty()) {
        tm -= pq.top().first;
        tt += tm-pq.top().second;
        pq.pop();
        while(idx<n and jobs[idx][0]<=tm) {
            pq.push({-jobs[idx][1], jobs[idx][0]});
            idx++;
        }
        if(pq.empty() and idx<n) {
            tm = jobs[idx][0];
            pq.push({-jobs[idx][1], jobs[idx][0]});
            idx++;
        }
    }
    
    int answer = tt/n;
    return answer;
}