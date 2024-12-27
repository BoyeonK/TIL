#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<bool> visited(100001);
	vector<int> pos(100001);
	vector<vector<pair<int, int>>> grp(100001);
	for (int i = 1; i <= 50000; i++) grp[i].push_back({ 0, 2 * i });
	for (int i = 0; i < 100000; i++) grp[i].push_back({ 1, i + 1 });
	for (int i = 1; i <= 100000; i++) grp[i].push_back({ 1, i - 1 });

	int N, K;
	priority_queue<pair<int, int>> pq;
	cin >> N >> K;
	pq.push({ 0, N });
	fill(pos.begin(), pos.end(), 2147483647);
	pos[N] = 0;

	int now, price, nxt, nxtprice;
	while (!pq.empty()) {
		price = -pq.top().first;
		now = pq.top().second;
		pq.pop();
		if (visited[now]) continue;
		visited[now] = true;
		if (visited[K]) break;
		for (auto a : grp[now]) {
			nxt = a.second;
			nxtprice = price + a.first;
			if (pos[nxt] > nxtprice) {
				pos[nxt] = nxtprice;
				pq.push({ -nxtprice, nxt });
			}
		}
	}
	cout << pos[K];
}