#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> parent(10001);
vector<int> childs;
priority_queue<pair<int, int>> pQ;

int root(int a) {
	if (parent[a] == a) {
		for (int& child : childs)
			parent[child] = a;
		childs.clear();
		return a;
	}
	else {
		childs.push_back(a);
		return root(parent[a]);
	}
}

bool merge(int a, int b) {
	a = root(a);
	b = root(b);
	if (a == b)
		return false;
	else {
		parent[a] = b;
		return true;
	}
}

void points(int& a, int& b, int p) {
	a = (p >> 15);
	b = p & 32767;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int V, E, A, B, C, sel = 0, ans = 0;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		pQ.push({ -C, (A << 15) + B });
	}
	for (int i = 0; i <= V; i++)
		parent[i] = i;

	while (sel < (V - 1)) {
		C = -pQ.top().first;
		points(A, B, pQ.top().second);
		pQ.pop();
		if (merge(A, B)) {
			sel += 1;
			ans += C;
		}
	}
	cout << ans;
}