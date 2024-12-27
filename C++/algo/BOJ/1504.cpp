#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> grp;
vector<int> dst;
vector<bool> ar;

int dijk(int s, int e) {
	int st, val, ed, cst;
	fill(dst.begin(), dst.end(), 2147483647);
	fill(ar.begin(), ar.end(), false);
	priority_queue<pair<int, int>> pq;
	dst[s] = 0;
	pq.push({ 0, s });
	while (!pq.empty()) {
		st = pq.top().second;
		val = -pq.top().first;
		pq.pop();
		if (ar[st]) continue;
		ar[st] = true;
		if (ar[e]) return val;
		for (auto a : grp[st]) {
			ed = a.second;
			cst = a.first;
			if (dst[ed] > val + cst) {
				dst[ed] = val + cst;
				pq.push({ -dst[ed], ed });
			}
		}
	}
	return 10000000;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int V, E, s, e, v, t1, t2;
	cin >> V >> E;
	grp.resize(V + 1);
	dst.resize(V + 1);
	ar.resize(V + 1);
	for (int i = 0; i < E; i++) {
		cin >> s >> e >> v;
		grp[s].push_back({ v,e });
		grp[e].push_back({ v,s });
	}
	cin >> t1 >> t2;

	int tt, w1, w2, ans;
	tt = dijk(t1, t2);
	w1 = tt + dijk(1, t1) + dijk(t2, V);
	w2 = tt + dijk(1, t2) + dijk(t1, V);
	ans = min(w1, w2);
	if (ans < 10000000) cout << ans;
	else cout << -1;
}