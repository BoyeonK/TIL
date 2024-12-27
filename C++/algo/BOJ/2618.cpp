#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int ttdst[1001][1001];
int tracker[1001][1001];
vector<pair<int, int>> Tpos;
vector<pair<int, int>> Fpos;

int sol_dst(int t, int f, bool TF) {
	int nxt = max(t, f) + 1;
	if (TF) return (abs(Tpos[nxt].first - Tpos[t].first) + abs(Tpos[nxt].second - Tpos[t].second));
	else return (abs(Fpos[nxt].first - Fpos[f].first) + abs(Fpos[nxt].second - Fpos[f].second));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	fill_n(&ttdst[0][0], 1001*1001, 2147483647);
	fill_n(&tracker[0][0], 1001 * 1001, 0);
	int N, W;
	cin >> N >> W;
	Tpos.resize(W + 1);
	Fpos.resize(W + 1);
	Tpos[0] = { 1, 1 };
	Fpos[0] = { N, N };
	int x, y;
	for (int i = 1; i <= W; i++) {
		cin >> x >> y;
		Tpos[i] = { x, y };
		Fpos[i] = { x, y };
	}
	ttdst[0][0] = 0;
	ttdst[1][0] = sol_dst(0, 0, true);
	ttdst[0][1] = sol_dst(0, 0, false);
	int now = 1, Tdst, Fdst;
	while (now < W) {
		for (int i = 0; i < now; i++) {
			Tdst = ttdst[now][i] + sol_dst(now, i, true);
			Fdst = ttdst[now][i] + sol_dst(now, i, false);
			ttdst[now + 1][i] = Tdst;
			tracker[now + 1][i] = tracker[now][i];
			if (ttdst[now][now + 1] > Fdst) {
				ttdst[now][now + 1] = Fdst;
				tracker[now][now + 1] = i;
			}

			Tdst = ttdst[i][now] + sol_dst(i, now, true);
			Fdst = ttdst[i][now] + sol_dst(i, now, false);
			ttdst[i][now + 1] = Fdst;
			tracker[i][now + 1] = tracker[i][now];
			if (ttdst[now+1][now] > Tdst) {
				ttdst[now+1][now] = Tdst;
				tracker[now + 1][now] = i;
			}
		}
		now++;
	}
	int mnm = 2147483647;
	pair<int, int> mnmPos;
	for (int i = 0; i < W; i++) {
		if (mnm > ttdst[i][W]) {
			mnm = ttdst[i][W];
			mnmPos = { i,W };
		}
		if (mnm > ttdst[W][i]) {
			mnm = ttdst[W][i];
			mnmPos = { W,i };
		}
	}
	cout << mnm << '\n';
	x = mnmPos.first;
	y = mnmPos.second;
	vector<int> backtrack;
	int dif;
	while (x != y) {
		dif = abs(x - y);
		if (x > y) {
			for (int i = 0; i < dif; i++) backtrack.push_back(1);
			x = tracker[x][y];
		}
		else {
			for (int i = 0; i < dif; i++) backtrack.push_back(2);
			y = tracker[x][y];
		}
	}
	reverse(backtrack.begin(), backtrack.end());
	for (auto a : backtrack) cout << a << '\n';
}