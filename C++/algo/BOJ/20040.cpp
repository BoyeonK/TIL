#include <iostream>
#include <vector>

using namespace std;

int parent[500000];
vector<int> childs;

int find(int i) {
	if (i == parent[i]) {
		for (int& child : childs)
			parent[child] = i;
		childs.clear();
		return i;
	}
	else {
		childs.push_back(i);
		return find(parent[i]);
	}
}

bool merge(int i, int j) {
	i = find(i);
	j = find(j);
	if (i == j)
		return true;
	else {
		parent[i] = j;
		return false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M, a, b, ans = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		parent[i] = i;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		if (merge(a, b)) {
			ans = i;
			break;
		}
	}
	cout << ans;
}