#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string T, P;
	getline(cin, T);
	getline(cin, P);
	int Tl = T.size(), Pl = P.size();
	vector<int> pi(Pl + 1);
	int idx = 1, matched = 0;

	while (idx + matched <= Pl) {
		if (P[idx + matched] == P[matched]) {
			matched++;
			pi[idx + matched] = matched;
		}
		else if (matched) {
			idx += matched - pi[matched];
			matched = pi[matched];
		}
		else
			idx++;
	}
	
	vector<int> matchedPosition;
	idx = 0; matched = 0;
	while (idx + matched <= Tl) {
		if (T[idx + matched] == P[matched] and matched < Pl)
			matched++;
		else if (matched) {
			if (matched == Pl)
				matchedPosition.push_back(idx);
			idx += matched - pi[matched];
			matched = pi[matched];
		}
		else
			idx++;
	}

	cout << matchedPosition.size() << endl;
	for (auto& n : matchedPosition)
		cout << (n + 1) << ' ';
}