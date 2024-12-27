#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, A;
	cin >> N;
	vector<int> NGE(N, -1);
	deque<pair<int, int>> Q;
	for (int i = 0; i < N; i++) {
		cin >> A;
		while (!Q.empty() && A > Q.front().second) {
			NGE[Q.front().first] = A;
			Q.pop_front();
		}
		Q.push_front({ i, A });
	}
	for (auto a : NGE) cout << a << ' ';
}