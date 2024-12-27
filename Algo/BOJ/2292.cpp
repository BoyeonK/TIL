#include <iostream>

int main() {
    int nm, i = 0;
    std::cin >> nm;
    while (nm > 3 * (i * i + i) + 1) i++;
    std::cout << i+1;
}