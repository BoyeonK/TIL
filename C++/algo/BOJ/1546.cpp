#include <iostream>

int main() {
    int sbj, score, mxm=0;
    double total = 0;
    std::cin >> sbj;
    for (int i=1; i<=sbj; i++) {
        std::cin >> score;
        total += score;
        if (score > mxm) mxm = score;
    }
    std::cout << total/mxm*100/sbj;
}