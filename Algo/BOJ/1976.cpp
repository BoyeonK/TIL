#include <iostream>
#include <vector>
#include <memory.h>
#include <string>

using namespace std;

vector<int> parent(201);
vector<int> childs;

int root(int n) {
	if (parent[n] == n) {
		for (int& c : childs)
			parent[c] = n;
		childs.clear();
		return n;
	}	
	else {
		childs.push_back(n);
		return root(parent[n]);
	}
}

void merge(int i, int j) {
	i = root(i);
	j = root(j);
	if (i != j)
		parent[i] = j;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M, inp, R;
	cin >> N >> M;
	for (int i = 0; i <= N; i++)
		parent[i] = i;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> inp;
			if (inp) 
				merge(i, j);
		}
	bool flag = true;
	string ans;
	cin >> inp;
	R = root(inp);
	for (int i = 1; i < M; i++) {
		cin >> inp;
		if (R != root(inp)) {
			flag = false;
			break;
		}
	}
	ans = (flag) ? "YES" : "NO";
	cout << ans;
}