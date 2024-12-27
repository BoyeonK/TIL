#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.second == b.second) return a.first < b.first;
	else return b.second > a.second;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, s, e, tbl = 0;
	vector<pair<int, int>> ac;
	cin >> N;
	while (N--) {
		cin >> s >> e;
		ac.push_back(make_pair(s, e));
	}
	sort(ac.begin(), ac.end(), cmp);
	e = 0;
	for (auto t : ac) {
		if (t.first >= e) {
			e = t.second;
			tbl += 1;
		}
	}
	cout << tbl;
}