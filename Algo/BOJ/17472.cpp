#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>

using namespace std;

int N, M;
bool map[101][101];
int parent[10000];
bool isbridge[10000];
int bridge[6][6];
vector<int> childs;

int find(int a) {
	if (a == -1)
		return -1;
	int p = parent[a];
	if (p == parent[p]) {
		if (!childs.empty()) {
			for (int& child : childs)
				parent[child] = p;
			childs.clear();
		}
		return p;
	}
	else {
		childs.push_back(a);
		return find(p);
	}
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if ((a == -1) || (b == -1))
		return;
	if (a != b) {
		if (a > b)
			swap(a, b);
		parent[b] = a;
	}
}

static int tp(int i, int j) {
	return (i * M + j);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(map, false, sizeof(map));
	memset(parent, -1, sizeof(parent));
	memset(isbridge, false, sizeof(isbridge));
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			bridge[i][j] = 1000;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j])
				parent[tp(i, j)] = tp(i, j);
		}

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			if (map[i][j]) {
				if (map[i + 1][j])
					merge(tp(i, j), tp(i + 1, j));
				if (map[i][j + 1])
					merge(tp(i, j), tp(i, j + 1));
			}


	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			if (map[i][j]) 
				isbridge[find(tp(i, j))] = true;

	vector<int> NtoTP;
	vector<int> TPtoN(10000);
	for (int i = 0; i < N * M; i++) 
		if (isbridge[i])
			NtoTP.push_back(i);
	int NN = NtoTP.size();
	for (int i = 0; i < NN; i++)
		TPtoN[NtoTP[i]] = i;

	int s, e, step;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j]) {
				s = find(tp(i, j));
				e = s;
				step = -1;
				for (int x = i + 1; x < N; x++) {
					step++;
					if (!map[x][j])
						continue;
					e = find(tp(x, j));
					break;
				}
				if ((s != e) && (step != 1) && (bridge[TPtoN[s]][TPtoN[e]] > step)) {
					bridge[TPtoN[s]][TPtoN[e]] = step;
				}
				e = s;
				step = -1;
				for (int y = j + 1; y < M; y++) {
					step++;
					if (!map[i][y])
						continue;
					e = find(tp(i, y));
					break;
				}
				if ((s != e) && (step != 1) && (bridge[TPtoN[s]][TPtoN[e]] > step)) {
					bridge[TPtoN[s]][TPtoN[e]] = step;
				}
			}
		}
	}

	priority_queue<pair<int, pair<int, int>>> pQ;
	int ans = 0, seq = 1, x, y, l;
	for (int i = 0; i < NN; i++)
		parent[i] = i;
	for (int i = 0; i < NN; i++)
		for (int j = i + 1; j < NN; j++) {
			if (bridge[i][j] > bridge[j][i]) 
				bridge[i][j] = bridge[j][i];
			if (bridge[i][j] != 1000) 
				pQ.push({ -bridge[i][j], {i,j} });
		}

	while (!pQ.empty()) {
		l = -pQ.top().first;
		x = pQ.top().second.first;
		y = pQ.top().second.second;
		pQ.pop();
		if (find(x) != find(y)) {
			merge(x, y);
			ans += l;
			seq++;
		}
		if (seq == NN)
			break;
	}
	if (seq != NN)
		ans = -1;
	cout << ans;
}