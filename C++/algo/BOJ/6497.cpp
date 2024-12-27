#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> parent;
vector<int> childs;

int find(int a) {
	int p = parent[a];
	if (p == parent[p]) {
		for (int& child : childs)
			parent[child] = p;
		childs.clear();
		return p;
	}
	else {
		childs.push_back(a);
		return find(p);
	}
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		parent[b] = a;
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M, a, b, l;
	long long point;
	while (true) {
		cin >> N >> M;
		if (N || M) {
			int tt = 0;
			priority_queue<pair<int, pair<int, int>>> pQ;
			parent.resize(N);
			for (int i = 0; i < N; i++)
				parent[i] = i;
			for (int i = 0; i < M; i++) {
				cin >> a >> b >> l;
				tt += l;
				pQ.push({ -l, {a, b} });
			}
			int seq = 1, ans = 0;
			while (seq != N) {
				a = pQ.top().second.first;
				b = pQ.top().second.second;
				if (merge(a, b)) {
					ans -= pQ.top().first;
					seq++;
				}
				pQ.pop();
			}
			cout << tt - ans << '\n';
			parent.clear();
		}
		else
			break;
	}
}