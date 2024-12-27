#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int main() {
	priority_queue<pair<int, int>> pQ;
	int n, m;
	cin >> n >> m;
	vector<int> ttdst(n + 1, 2147483647);
	vector<int> tracker(n + 1, -1);
	vector<vector<pair<int, int>>> grp(n + 1);
	int s, e, l;
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> l;
		grp[s].push_back({ -l, e });
	}
	cin >> s >> e;
	pQ.push({ 0, s });
	ttdst[s] = 0;
	int dst, nxtdst, now, nxt;
	while (!pQ.empty()) {
		now = pQ.top().second;
		dst = pQ.top().first;
		pQ.pop();
		if (-dst > ttdst[now]) continue;
		for (auto bus : grp[now]) {
			nxt = bus.second;
			nxtdst = dst + bus.first;
			if (ttdst[nxt] > -nxtdst) {
				pQ.push({ nxtdst, nxt });
				ttdst[nxt] = -nxtdst;
				tracker[nxt] = now;
			}
		}
	}
	cout << ttdst[e];
	deque<int> ans;
	while (e != -1) {
		ans.push_front(e);
		e = tracker[e];
	}
	cout << '\n' << ans.size() << '\n';
	for (int i : ans) cout << i << ' ';
}