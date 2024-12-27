#include <iostream>
#include <vector>

using namespace std;

int N, C, inp;
vector<int> cr;
bool inpr = true, valc[501];

void acm(int dp, int tt, int comb) {
	if (inpr) {
		if (dp >= C) {
			if (tt == 888888) {
				for (int i = 0; i < N; i++) if (valc[i]) cout << i << ' ';
				inpr = false;
			}
			return;
		}
		else {
			for (int i = comb; i < N; i++) {
				if (!valc[i]) {
					valc[i] = true;
					acm(dp + 1, tt + cr[i], i + 1);
					valc[i] = false;
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> inp;
		cr.push_back(inp);
	}
	acm(0, 0, 0);
}