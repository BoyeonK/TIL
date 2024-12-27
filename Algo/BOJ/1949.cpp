#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> grp(10001);
vector<bool> visited(10001);
vector<int> sel(10001);
vector<int> nsel(10001);

void dfs(int u) {
	visited[u] = true;
	for (int& d : grp[u]) {
		if (!visited[d]) {
			dfs(d);
			sel[u] += nsel[d];
			nsel[u] += max(sel[d], nsel[d]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, a, b;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> sel[i];
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		grp[a].push_back(b);
		grp[b].push_back(a);
	}
	dfs(1);
	cout << max(sel[1], nsel[1]);
}