#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cookie) {
    int n = cookie.size();
    vector<int> asum;
    int sum = 0, mxm = 0;
    asum.push_back(0);
    for (int i = 0; i < n; i++) {
        sum += cookie[i];
        asum.push_back(sum);
    }
    
    for (int i = 0; i <= n; i++) {
        int mv = asum[i], li = 0, ri = n;
        while (true) {
            int lv = mv - asum[li], rv = asum[ri] - mv;
            if (mxm > lv or mxm > rv or i == li or i == ri)
                break;
            if (lv == rv) {
                if (rv > mxm)
                    mxm = rv;
                break;
            }
            if (lv > rv)
                li += 1;
            else
                ri -= 1;
        }
    }
    return mxm;
}