#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    int s = works.size();
    sort(works.rbegin(), works.rend());
    vector<int> ttdst(s);
    for (int i = 0; i < (s - 1); i++)
        ttdst[i] = (works[i] - works[i + 1]) * (i + 1);
    ttdst[s - 1] = works[s - 1] * s;
    int idx = 0;
    while (n >= ttdst[idx] and idx < s) {
        n -= ttdst[idx];
        idx++;
    }
    if (idx != s) {
        for (int i = 0; i < idx; i++) {
            works[i] = works[idx];
        }
        idx++;
        int a = n / idx;
        int b = n % idx;
        for (int i = 0; i < idx; i++) {
            works[i] -= a;
        }
        for (int i = 0; i < b; i++) {
            works[i] -= 1;
        }
        for (auto w : works)
            answer += w*w;
    }
    return answer;
}