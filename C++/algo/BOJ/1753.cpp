#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int V, E, st, s, e, v;
	cin >> V >> E >> st;
	vector<bool> arvd(V + 1);
	vector<vector<pair<int, int>>> grp(V + 1);
	vector<int> dst(V + 1, 30000001);
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < E; i++) {
		cin >> s >> e >> v;
		grp[s].push_back({ v, e });
	}
	dst[st] = 0;
	pq.push({ 0, st });
	while (!pq.empty()) {
		v = -pq.top().first;
		s = pq.top().second;
		pq.pop();
		if (arvd[s]) continue;
		arvd[s] = true;
		for (auto a : grp[s]) {
			e = a.second;
			if (dst[e] > a.first + v) {
				dst[e] = a.first + v;
				pq.push({ -dst[e], e });
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dst[i] == 30000001) cout << "INF" << '\n';
		else cout << dst[i] << '\n';
	}
}