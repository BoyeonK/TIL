#include <string>
#include <vector>
#include <queue>

using namespace std;

int StoI(string& ts) {
    int num = 0;
    num += 60 * stoi(ts.substr(0, 2));
    num += stoi(ts.substr(3, 2));
    return num;
}

string ItoS(int ti) {
    string s = "";
    int h = ti / 60, m = ti % 60;
    if (h < 10) s += "0";
    s = s + to_string(h) + ":";
    if (m < 10) s += "0";
    s = s + to_string(m);
    return s;
}

string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> baechar;
    for (int i = 0; i < n; i++)
        baechar.push_back(540 + t * i);
    vector<bool> isfull;
    vector<int> boundary(baechar);
    priority_queue<int> pq;
    for (auto& s : timetable)
        pq.push(-StoI(s));

    int idx = 0, count = 0;
    int a;
    while (!pq.empty()) {
        int t = -pq.top();
        if (t > boundary[idx]) {
            count = 0;
            idx++;
            if (idx == n)
                break;
        }
        else {
            pq.pop();
            count += 1;
            if (count == m) {
                boundary[idx] = t - 1;
                count = 0;
                idx++;
                if (idx == n)
                    break;
            }
        }
    }
    a = boundary[n - 1];
    string ans = ItoS(a);
    return ans;
}