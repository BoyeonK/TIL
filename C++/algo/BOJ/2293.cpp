#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K, c;
    cin >> N >> K;
    vector<int> DP(K + 1);
    DP[0] = 1;
    while (cin >> c) for (int j = 0; j <= K - c; j++) if (DP[j]) DP[j + c] += DP[j];
    cout << DP[K];
}