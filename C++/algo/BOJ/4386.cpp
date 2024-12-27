#include <iostream>
#include <vector>
#include <memory.h>
#include <cmath>
#include <queue>

using namespace std;
vector<pair<double, double>> points(100);
double dst[100][100];
vector<double> ttdst(100);
vector<bool> visited(100);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	double x, y;
	cin >> N;
	memset(dst, 0, sizeof(dst));
	fill(ttdst.begin(), ttdst.end(), 2000);
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		points[i] = { x, y };
	}
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++) {
			x = points[i].first - points[j].first;
			y = points[i].second - points[j].second;
			dst[i][j] = sqrt(x * x + y * y);
			dst[j][i] = dst[i][j];
		}

	int p = 0, mi, trial = N;
	double mnm = 2000, ans = 0;
	visited[0] = true;
	while (--trial) {
		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				if (ttdst[i] > dst[p][i])
					ttdst[i] = dst[p][i];
				if (mnm > ttdst[i]) {
					mnm = ttdst[i];
					mi = i;
				}
			}
		}
		visited[mi] = true;
		ans += mnm;
		mnm = 2000;
		p = mi;
	}
	cout << ans;
}