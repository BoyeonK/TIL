#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int K, V, E, s, e;
	cin >> K;
	while (K--) {
		bool tm = false;
		string ans;
		cin >> V >> E;
		vector<bool> cV(V + 1, true);
		vector<bool> tmar(V + 1);
		vector<vector<int>> grp(V + 1);
		vector<int> Q;
		vector<int> nxQ;

		for (int i = 0; i < E; i++) {
			cin >> s >> e;
			grp[s].push_back(e);
			grp[e].push_back(s);
			cV[s] = false;
			cV[e] = false;
		}

		nxQ.push_back(s);
		cV[s] = true;
		while (!nxQ.empty()) {
			Q = nxQ;
			nxQ.clear();
			for (int st : Q) for (int ed : grp[st]) {
				if (!cV[ed]) {
					cV[ed] = true;
					tmar[ed] = !tm;
					nxQ.push_back(ed);
				}
				else if (tmar[ed] == tm) {
					ans = "NO";
					goto edt;
				}
			}
			tm = !tm;
			if (nxQ.empty()) {
				for (int i = 1; i <= V; i++) {
					if (!cV[i]) nxQ.push_back(i);
					break;
				}
			}
		}

		ans = "YES";
	edt:
		cout << ans << '\n';
	}
}