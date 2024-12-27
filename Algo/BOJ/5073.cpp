#include <iostream>

int main() {
    int A, B, C, N, temp;
    while (std::cin >> A >> B >> C) {
        N = 0;
        if (A) {
            if (A > B) {
                temp = B;
                B = A;
                A = temp;
            }
            else if (A == B) N++;
            if (B > C) {
                temp = C;
                C = B;
                B = temp;
                if (A == B) N++;
            }
            else if (B == C) {
                N++;
            }
            if (C >= A + B) {
                std::cout << "Invalid" << '\n';
            }
            else {
                switch (N) {
                case 0: std::cout << "Scalene" << '\n'; break;
                case 1: std::cout << "Isosceles" << '\n'; break;
                case 2: std::cout << "Equilateral" << '\n'; break;
                }
            }
        }
        else break;
    }
}