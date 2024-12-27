#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int s, e, N;
	cin >> s >> e;
	N = s + e;
	vector<bool> vst(101);
	vector<int> grp(101);
	for (int i = 0; i <= 100; i++) grp[i] = i;
	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		grp[s] = e;
	}
	deque<pair<int, int>> Q{ {1, 0} };
	int seq, obj;
	while (1) {
		seq = Q.front().second;
		for (int i = 1; i <= 6; i++) {
			obj = grp[Q.front().first + i];
			if (obj == 100) {
				cout << seq + 1;
				return 0;
			}
			else if (!vst[obj]) {
				Q.push_back({ obj, seq + 1 });
				vst[obj] = true;
			}
		}
		Q.pop_front();
	}
}