#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

bool cpr(pair<string, int> a, pair<string, int> b) {
	if (a.second == b.second) {
		if (a.first.size() == b.first.size()) {
			return a.first < b.first;
		}
		return a.first.size() > b.first.size();
	}
	return a.second > b.second;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N, M;
	cin >> N >> M;
	string wd;
	unordered_map<string, int> ct;
	while (N--) {
		cin >> wd;
		if (wd.size() >= M) {
			if (ct[wd]) ct[wd] += 1;
			else ct[wd] = 1;
		}
	}
	vector<pair<string, int>> arr(ct.begin(), ct.end());
	sort(arr.begin(), arr.end(), cpr);
	for (auto p : arr) cout << p.first << '\n';
}