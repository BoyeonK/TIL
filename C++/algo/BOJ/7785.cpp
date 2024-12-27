#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	map<string, bool> Geegle;
	string nm, ob;
	vector<string> order;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nm >> ob;
		if (ob[0] == 'e') Geegle[nm] = true;
		else Geegle[nm] = false;
	}

	for (auto it = Geegle.begin(); it != Geegle.end(); it++) if (it->second) order.push_back(it->first);

	sort(order.begin(), order.end());

	for (int i = order.size() - 1; i >= 0; i--) cout << order[i] << '\n';
}