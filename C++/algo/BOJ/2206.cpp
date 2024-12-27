#include <iostream>
#include <deque>
#include <tuple>

using namespace std;

int N, M, dx[]{ 0,1,0,-1 }, dy[]{ 1,0,-1,0 };
char mp[1001][1001];
bool step[1001][1001]{}, ustep[1001][1001]{};

bool val(int x, int y) {
	if (x < N && x >= 0 && y < M && y >= 0) return true;
	else return false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> mp[i];
	deque<tuple<int, int, bool, int>> Q;
	step[0][0] = true; ustep[0][0] = true;
	Q.push_back({ 0, 0, true, 1 });
	int x, y, xx, yy, seq;
	bool brk;
	while (!Q.empty()) {
		tie(x, y, brk, seq) = Q.front();
		Q.pop_front();
		if (x == N - 1 && y == M - 1) {
			cout << seq;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			xx = x + dx[i];
			yy = y + dy[i];
			if (val(xx, yy)) {
				if (!step[xx][yy] && brk) {
					if (mp[xx][yy] == '0') Q.push_back({ xx, yy, true, seq + 1 });
					else Q.push_back({ xx, yy, false, seq + 1 });
					step[xx][yy] = true;
					ustep[xx][yy] = true;
				}
				else if (!ustep[xx][yy] && mp[xx][yy] == '0') {
					Q.push_back({ xx, yy, false, seq + 1 });
					ustep[xx][yy] = true;
				}
			}
		}
	}
	cout << -1;
}