#include <iostream>
#include <vector>
#include <cmath>
#include <memory.h>

using namespace std;
vector<pair<int, int>> points(1001);
double dist[1001][1001];
vector<int> parents(1001);
vector<int> childs;
int N, M, x, y, merged = 0;

int root(int a) {
	int p = parents[a];
	if (p == parents[p]) {
		if (!childs.empty()) {
			for (int& child : childs)
				parents[child] = p;
			childs.clear();
		}
		return p;
	}
	else {
		childs.push_back(a);
		return root(p);
	}
}

void merge(int a, int b) {
	a = root(a);
	b = root(b);
	if (a != b) {
		if (a > b)
			swap(a, b);
		for (int i = 1; i <= N; i++)
			if (dist[a][i] > dist[b][i])
				dist[a][i] = dist[b][i];
		parents[b] = a;
		merged++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> x >> y;
		points[i] = { x, y };
		parents[i] = i;
	}
	double X, Y;
	for (int i = 1; i <= N; i++) {
		dist[i][i] = 0;
		for (int j = i + 1; j <= N; j++) {
			X = points[i].first - points[j].first;
			Y = points[i].second - points[j].second;
			dist[i][j] = sqrt(pow(X, 2) + pow(Y, 2));
			dist[j][i] = dist[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		merge(x, y);
	}

	double* ttdst = dist[1];
	double mnm = 2000000;
	double ans = 0;
	int mi;
	while (merged < N - 1) {
		for (int i = 1; i <= N; i++) {
			if ((root(i) != 1) && (mnm > ttdst[i])) {
				mnm = ttdst[i];
				mi = i;
			}
		}
		ans += mnm;
		merge(1, mi);
		mnm = 2000000;
	}

	cout << fixed;
	cout.precision(2);
	cout << ans;
}