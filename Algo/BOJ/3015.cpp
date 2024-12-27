#include <iostream>
#include <deque>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, ht;
	long long ans = 0;
	deque<pair<int, int>> Q;
	cin >> N;
	while (N--) {
		cin >> ht;
		while (!Q.empty() && ht > Q.front().first) {
			ans += Q.front().second;
			Q.pop_front();
		}
		for (auto a : Q) {
			if (a.first > ht) {
				ans += 1;
				break;
			}
			else ans += a.second;
		}
		if (!Q.empty() && Q.front().first == ht) Q.front().second += 1;
		else Q.push_front({ ht, 1 });
	}
	cout << ans;
}