#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited(100001);
vector<vector<int>> E;
vector<int> odr, ans(100001);
int od = 0, P;

void bfs() {
	if (od == odr.size()) return;
	P = odr[od];
	ans[P] = od + 1;
	for (auto e : E[P]) if (!visited[e]) { 
		odr.push_back(e);
		visited[e] = true;
	}
	od++;
	bfs();
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M, R, s, e;
	cin >> N >> M >> R;
	E.resize(N + 1);
	while (M--) {
		cin >> s >> e;
		E[s].push_back(e);
		E[e].push_back(s);
	}
	for (auto &l : E) sort(l.begin(), l.end());
	odr.push_back(R);
	visited[R] = true;
	bfs();
	for (int i = 1; i <= N; i++) cout << ans[i] << '\n';
}