#include <iostream>

int main() {
    int n;
    std::cin >> n >> n;
    int mnm = n, mxm = n;
    while (std::cin >> n) {
        if (n>mxm)
            mxm=n;
        if (n<mnm)
            mnm=n;
    }
    std::cout << mnm << " " << mxm;
}