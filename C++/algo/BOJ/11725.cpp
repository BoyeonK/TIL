#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, a, b;
	cin >> N;
	vector<vector<int>> grp(N+1);
	vector<int> root(N + 1, 0);
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		grp[a].push_back(b);
		grp[b].push_back(a);
	}
	vector<int> Q{1};
	root[1] = -1;
	int now;
	for (int i = 0; i < N; i++) {
		now = Q[i];
		for (int a : grp[now]) {
			if (!root[a]) {
				root[a] = now;
				Q.push_back(a);
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		cout << root[i] << '\n';
	}
}