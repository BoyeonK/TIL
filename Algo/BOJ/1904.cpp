#include <iostream>

int main() {
    int N, ans, arr[4];
    for (int i = 0; i < 4; i++) arr[i] = i + 1 + i / 3;
    std::cin >> N;
    if (N > 4) {
        for (int j = 0; j < N - 4; j++) {
            for (int k = 0; k < 3; k++) arr[k] = arr[k + 1];
            arr[3] = (2 * arr[1] + arr[0]) % 15746;
        }
        ans = arr[3];
    }
    else {
        ans = arr[N - 1];
    }
    std::cout << ans;
}