#include <iostream>

int main() {
    int inpt, mxm=1, cnt=1, i=1;
    while (std::cin >> inpt) {
        if (inpt > mxm) {
            mxm = inpt;
            cnt = i;
        }
        i++;
    }
    std::cout << mxm << '\n' << cnt << std::endl;
}