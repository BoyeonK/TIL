#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<string> lines) {
    vector<int> st;
    vector<int> et;
    for (string& log : lines) {
        string date, cts, drts;
        int ct, drt;
        stringstream ss(log);
        ss >> date >> cts >> drts;
        if (date != "2016-09-15")
            continue;
        ct = stoi(cts.substr(0, 2)) * 3600000 + stoi(cts.substr(3, 2)) * 60000 + stoi(cts.substr(6, 2)) * 1000 + stoi(cts.substr(9, 3));
        drt = stoi(drts.substr(0, 1)) * 1000;
        if (drts.size() > 2) 
            drt += stoi(drts.substr(2, drts.size() - 3)) * pow(10, 6 - drts.size());
        et.push_back(ct);
        st.push_back(ct - drt + 1);
    }
    sort(st.begin(), st.end());
    int sidx = 0, eidx = 0, tc, prc = 0, mxm = 0, n = st.size();
    tc = -3001;
    while (sidx != n) {
        int ds = (sidx < n) ? st[sidx] - (tc + 1000) : 2147483647;
        int de = et[eidx] - tc;
        if (de > ds) {
            tc += ds;
            prc += 1;
            sidx += 1;
            if (prc > mxm) mxm = prc;
        }
        else {
            tc += de;
            prc -= 1;
            eidx += 1;
        }
    }
    return mxm;
}