#include <iostream>
#include <deque>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	string ls, ss;
	cin >> ls >> ss;
	int chain = 0, N = ls.length(), M = ss.length();
	char alp, trg = ss.back();
	deque<char> ans;
	deque<char>::iterator iter;
	for (int i = 0; i < N; i++) {
		alp = ls[i];
		ans.push_back(alp);
		if (alp == trg && ans.size() >= M) {
			iter = ans.end() - M;
			for (int j = 0; j < M; j++) {
				//cout << *(iter + j);
				if (*(iter + j) == ss[j]) chain += 1;
				else break;
			}
			if (chain == M) while (chain--) ans.pop_back();
			chain = 0;
		}
	}
	if (ans.empty()) cout << "FRULA";
	else {
		ls.clear();
		for (auto a : ans) ls += a;
		cout << ls;
	}
}