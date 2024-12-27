#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> grp(100001);
vector<bool> done(100001, false);
vector<int> DP(100001, -1);
vector<int> ans(100001, 0);
queue<int> Q;

void draw_grp(int now, int nxt) {
	if (nxt >= 0 and nxt <= 100000) grp[now].push_back(nxt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N, K, f, b, t;
	for (int i = 0; i <= 100000; i++) {
		f = i - 1; b = i + 1; t = 2 * i;
		draw_grp(i, f);
		draw_grp(i, b);
		draw_grp(i, t);
	}
	cin >> N >> K;
	DP[N] = -2;
	Q.push(N);
	int now;
	while (DP[K] == -1 and !Q.empty()) {
		now = Q.front();
		Q.pop();
		if (done[now] == true) continue;
		done[now] = true;
		for (int nxt : grp[now]) {
			if (nxt >= 0 and nxt <= 100000 and DP[nxt] == -1) {
				DP[nxt] = now;
				Q.push(nxt);
			}
		}
	}
	int idx = -1;
	while (K != -2) {
		idx++;
		ans[idx] = K;
		K = DP[K];
	}
	cout << idx << '\n';
	for (int i = idx; i >= 0; i--) cout << ans[i] << ' ';
}