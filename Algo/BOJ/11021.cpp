#include <iostream>

int main() {
    int trial, alpha, beta;
    std::cin >> trial;
    for (int i = 1; i <= trial; i++) {
        std::cin >> alpha >> beta;
        std::cout << "Case #" << i << ": " << alpha+beta << std::endl;
    }
}