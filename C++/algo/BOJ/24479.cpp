#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited(100001);
vector<vector<int>> E;
vector<int> odr(100001);
int od = 1;

void dfs(int R) {
	visited[R] = true;
	odr[R] = od++;
	for (auto e : E[R]) {
		if (!visited[e]) dfs(e);
	}
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
	dfs(R);
	for (int i = 1; i <= N; i++) cout << odr[i] << '\n';
}