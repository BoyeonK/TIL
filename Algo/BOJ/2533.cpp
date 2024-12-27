#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> grp(1000001);
vector<bool> visited(1000001);
vector<int> sel(1000001);
vector<int> nsel(1000001);

void dfs(int u) {
	sel[u] = 1;
	visited[u] = true;
	for (int& d : grp[u]) {
		if (!visited[d]) {
			dfs(d);
			sel[u] += min(sel[d], nsel[d]);
			nsel[u] += sel[d];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, a, b;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		grp[a].push_back(b);
		grp[b].push_back(a);
	}
	dfs(1);
	cout << min(sel[1], nsel[1]);
}