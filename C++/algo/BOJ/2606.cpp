#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, s, e;
	cin >> N;
	vector<vector<int>> grp(N + 1);
	vector<bool> isift(N + 1);
	isift[1] = true; 
	vector<int> ift{ 1 };
	cin >> N;
	while (N--) {
		cin >> s >> e;
		grp[s].push_back(e);
		grp[e].push_back(s);
	} 
	int nw = 0, spcn;
	while (true) {
		if (nw == ift.size()) break;
		spcn = ift[nw];
		for (int cn : grp[spcn]) { 
			if (!isift[cn]) {
				ift.push_back(cn);
				isift[cn] = true;
			}
		}
		nw++;
	}
	cout << ift.size()-1;
}