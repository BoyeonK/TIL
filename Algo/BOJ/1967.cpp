#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> grp;
vector<bool> visited;
int mxm = 0, ed;

void dfs(int i, int length) {
	visited[i] = true;
	if (length > mxm) {
		mxm = length;
		ed = i;
	}
	for (auto &a : grp[i]) 
		if(!visited[a.first]) 
			dfs(a.first, length + a.second);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, a, b, l;
	cin >> N;
	grp.resize(N + 1);
	visited.resize(N + 1);
	for (int i = 1; i < N; i++) {
		cin >> a >> b >> l;
		grp[a].push_back({ b, l });
		grp[b].push_back({ a, l });
	}
	dfs(1, 0);
	fill(visited.begin(), visited.end(), false);
	dfs(ed, 0);
	cout << mxm;
}