#include <iostream>

int main() {
    int N, ans, pr, cr, arr[3] = { 0, };
    std::cin >> N;
    for (int i = 0; N > i && 3 > i; i++) { 
        std::cin >> pr;
        arr[i] = pr;
    }
    arr[2] = (arr[1] > arr[0]) ? arr[1] + arr[2] : arr[0] + arr[2];
    arr[1] += arr[0];
    if (N > 3) {
        for (int i = 3; N > i; i++) {
            std::cin >> cr;
            ans = (arr[0] + pr > arr[1]) ? arr[0] + pr + cr : arr[1] + cr;
            arr[0] = arr[1];
            arr[1] = arr[2];
            arr[2] = ans;
            pr = cr;
        }
    }
    else if (N == 0) ans = 0;
    else ans = arr[N - 1];
    std::cout << ans;
}