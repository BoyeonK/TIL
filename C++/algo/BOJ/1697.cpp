#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int nxt(int X, int i) {
	switch (i) {
	case(0):
		return X - 1;
	case(1):
		return X + 1;
	case(2):
		return 2 * X;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, K, nw, nx, seq;
	cin >> N >> K;
	if (N == K) {
		cout << 0;
		return 0;
	}
	vector<bool> pos(100001);
	pos[N] = true;
	deque<pair<int, int>> Q{ {N, 0} };
	while (true) {
		nw = Q.front().first;
		seq = Q.front().second;
		for (int i = 0; i < 3; i++) {
			nx = nxt(nw, i);
			if (nx == K) {
				cout << seq + 1;
				return 0;
			}
			else if (!pos[nx] && nx<=100000 && nx>0) {
				pos[nx] = true;
				Q.push_back({ nx, seq + 1 });
			}
		}
		Q.pop_front();
	}
}