#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M, inp, tc = 1;
    cin >> N >> M;
    int* mmr = new int[N];
    int* cst = new int[10001] {};
    int* CST = new int[10001] {};
    for (int i = 0; i < N; i++) {
        cin >> inp;
        mmr[i] = inp;
    }
    for (int i = 0; i < N; i++) {
        cin >> inp;
        if (inp) {
            CST[inp] = max(cst[inp], mmr[i]);
            for (int j = 1; j <= tc; j++) {
                if (cst[j]) CST[j + inp] = max(cst[j + inp], cst[j] + mmr[i]);
            }
            tc += inp;
            for (int j = 1; j <= tc; j++) cst[j] = CST[j];
        }
        else {
            M -= mmr[i];
        }
    }
    for (int i = 0; i < tc; i++) {
        if (cst[i] >= M) {
            cout << i;
            return 0;
        }
    }
}