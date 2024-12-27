#include <iostream>
#include <vector>

using namespace std;

vector<int> sel(10001);
vector<int> nsel(10001);
vector<vector<int>> grp;
vector<bool> visited(10001);
vector<bool> selected(10001);

void dfs(int n) {
	visited[n] = true;
	for (int& e : grp[n]) {
		if (!visited[e]) {
			dfs(e);
			sel[n] += nsel[e];
			nsel[n] += max(sel[e], nsel[e]);
		}
	}
}

void trace(int n, bool issel) {
	visited[n] = true;
	if ((sel[n] > nsel[n]) && !issel)
		selected[n] = true;
	for (int& e : grp[n])
		if (!visited[e])
			trace(e, selected[n]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, s, e;
	cin >> N;
	grp.resize(N + 1);
	for (int i = 1; i <= N; i++)
		cin >> sel[i];
	for (int i = 1; i < N; i++) {
		cin >> s >> e;
		grp[s].push_back(e);
		grp[e].push_back(s);
	}
	dfs(1);
	fill(visited.begin(), visited.end(), false);
	trace(1, false);
	cout << max(sel[1], nsel[1]) << '\n';
	for (int i = 1; i <= N; i++)
		if (selected[i])
			cout << i << ' ';
}