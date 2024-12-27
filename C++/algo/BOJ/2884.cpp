#include <iostream>

int main() {
    int hour, minute, time, quo;
    std::cin >> hour >> minute;
    time = 60*hour + minute;
    time = time - 45;
    if (time < 0)
        time = time + 24*60;
    quo = time / 60;
    std::cout << quo << " " << time%60;
}