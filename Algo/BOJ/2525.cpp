#include <iostream>

int main() {      
    int hr, mnt, ct, tt, quo;
    std::cin >> hr >> mnt >> ct;
    tt = hr*60 + mnt + ct;
    if (tt>=24*60)
        tt= tt-24*60;
    quo = tt/60;
    std::cout << quo << " " << tt%60;
}