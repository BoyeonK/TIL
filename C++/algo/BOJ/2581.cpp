#include <iostream>
#include <cmath>

int main() {
    int M, N, mnm = 0, tt = 0;
    bool ss;
    std::cin >> M >> N;
    for (int i = M; i <= N; i++) {
        ss = true;
        if (i == 1) ss = false;
        else if (i % 2 == 0 && i != 2) ss = false;
        else if (i % 2) {
            for (int j = 1; (2 * j + 1) <= sqrt(i); j++) {
                if ((i % (2 * j + 1)) == 0) ss = false;
            }
        }
        if (ss) {
            if (!mnm) mnm = i;
            tt += i;
        }
    }
    if (mnm) std::cout << tt << '\n' << mnm;
    else std::cout << -1;
}