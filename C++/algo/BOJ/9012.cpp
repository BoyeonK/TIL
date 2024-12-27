#include <iostream>
#include <deque>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	bool VPS = true;
	string PS;
	cin >> N;
	deque<char> PSC;
	for (int i = 0; i < N; i++) {
		cin >> PS;
		for (int j = 0; j < PS.size(); j++) {
			if (PS[j] == '(') PSC.push_back('(');
			else {
				if (PSC.size()) PSC.pop_back();
				else {
					VPS = false;
					break;
				}
			}
		}
		if (PSC.size()) VPS = false;
		if (VPS) cout << "YES" << '\n';
		else cout << "NO" << '\n';
		VPS = true;
		PSC.clear();
	}
}