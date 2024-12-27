#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

priority_queue<pair<int, int>> pq;
vector<int> fromS, fromG, fromH;
vector<bool> visited;
vector<vector<pair<int, int>>> grp;

void dijk(vector<int> &from, int target, int n) {
	int now, dst, nxt, nxtdst;
	from.resize(n + 1);
	fill(from.begin(), from.end(), 2147483647);
	fill(visited.begin(), visited.end(), false);
	pq.push({ 0, target });
	from[target] = 0;
	while (!pq.empty()) {
		dst = -pq.top().first;
		now = pq.top().second;
		pq.pop();
		if (visited[now]) continue;
		visited[now] = true;
		for (auto a : grp[now]) {
			nxtdst = a.first + dst;
			nxt = a.second;
			if (from[nxt] > nxtdst) {
				from[nxt] = nxtdst;
				pq.push({ -nxtdst, nxt });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, n, m, t, s, g, h, a, b, d, GtoH;
	cin >> N;
	while (N--) {
		cin >> n >> m >> t >> s >> g >> h;
		grp.clear();
		grp.resize(n + 1);
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> d;
			if ((a == g and b == h) or (a == h and b == g)) GtoH = d;
			grp[a].push_back({ d, b });
			grp[b].push_back({ d, a });
		}
		vector<int> cnd(t);
		for (int i = 0; i < t; i++) cin >> cnd[i];
		sort(cnd.begin(), cnd.end());

		visited.resize(n + 1);
		dijk(fromS, s, n);
		dijk(fromG, g, n);
		dijk(fromH, h, n);

		int SA, SGHA, SHGA;
		for (auto arrival : cnd) {
			SA = fromS[arrival];
			SGHA = fromS[g] + GtoH + fromH[arrival];
			SHGA = fromS[h] + GtoH + fromG[arrival];
			if (SA == SGHA or SA == SHGA) {
				cout << arrival << ' ';
			}
		}
		cout << '\n';
	}
}