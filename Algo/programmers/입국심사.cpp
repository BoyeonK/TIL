#include <string>
#include <vector>

using namespace std;

vector<int> tv;

long long howManyPerson(long long time) {
    long long n = 0;
    for (auto numer : tv)
        n += (time / numer);
    return n;
}

long long solution(int n, vector<int> times) {
    long long N = n;
    long long answer = 0;
    long long l = 0, lv = 0;
    long long r = 100000000000000, rv;
    long long m, mv;
    long long min = 2147483647;
    tv = times;

    while (true) {
        m = (l + r) / 2;
        mv = howManyPerson(m);
        if (mv == N)
            break;
        if (l == m) {
            if (howManyPerson(l) == N)
                m = l;
            else
                m = r;
            break;
        }
        else {
            if (mv > N)
                r = m;
            else
                l = m;
        }
    }
    for (auto time : times) {
        int modt = m % time;
        if (min > modt)
            min = modt;
    }
    m -= min;
    return m;
}