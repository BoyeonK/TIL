#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N, ttwg = 0, ac = 0, inp;
    cin >> N;
    vector<int> wg(N);
    for (int i = 0; i < N; i++) {
        cin >> wg[i];
        ttwg += wg[i];
    }
    vector<bool> dp1(ttwg + 1), dp2(ttwg + 1);
    dp1[0] = true;
    dp2[0] = true;
    for (auto wgt : wg) {
        for (int i = 0; i <= ac; i++) {
            if (dp1[i]) {
                dp2[abs(i + wgt)] = true;
                dp2[abs(i - wgt)] = true;
            }
        }
        ac += wgt;
        dp1 = dp2;
    }
    cin >> N;
    while (N--) {
        cin >> inp;
        if (inp <= ttwg && dp1[inp]) cout << "Y ";
        else cout << "N ";
    }
}