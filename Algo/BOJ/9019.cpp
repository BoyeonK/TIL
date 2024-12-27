#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	vector<vector<int>> grp(10000);
	int N, D, S, L, R, a, d;
	cin >> N;
	for (int i = 0; i < 10000; i++) {
		D = (i * 2) % 10000;
		S = (i == 0) ? 9999 : i - 1;
		a = i / 1000;
		d = i % 10;
		L = (i * 10) % 10000 + a;
		R = (i / 10) + d * 1000;
		grp[i] = { D, S, L, R };
	}
	int s, e, now, nxt;
	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		queue<int> Q;
		vector<pair<int, int>> tracker(10000);
		vector<bool> visited(10000, false);
		Q.push(s);
		visited[s] = true;
		tracker[s] = { -1, -1 };
		while (!visited[e]) {
			now = Q.front();
			Q.pop();
			for (int i = 0; i < 4; i++) {
				nxt = grp[now][i];
				if (!visited[nxt]) {
					Q.push(nxt);
					visited[nxt] = true;
					tracker[nxt].first = now;
					tracker[nxt].second = i;
				}
			}
		}
		string ans;
		while (e != s) {
			switch (tracker[e].second) {
			case 0:
				ans += 'D';
				break;
			case 1:
				ans += 'S';
				break;
			case 2:
				ans += 'L';
				break;
			case 3:
				ans += 'R';
				break;
			}
			e = tracker[e].first;
		}
		reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}
}