#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	map<string, bool> DJ;
	vector<string> DBJ;
	string nm;
	for (int i = 0; i < N; i++) {
		cin >> nm;
		DJ[nm] = true;
	}
	for (int j = 0; j < M; j++) {
		cin >> nm;
		if (DJ[nm]) DBJ.push_back(nm);
	}
	sort(DBJ.begin(), DBJ.end());

	cout << DBJ.size() << '\n';
	for (int k = 0; k < DBJ.size(); k++) {
		cout << DBJ[k] << '\n';
	}
}