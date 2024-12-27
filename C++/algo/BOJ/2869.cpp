#include <iostream>

int main() {
    int A, B, V, ans;
    std::cin >> A >> B >> V;
    ans = ((V - A) % (A - B) == 0) ? (V - A) / (A - B) + 1 : (V - A) / (A - B) + 2;
    std::cout << ans;
}