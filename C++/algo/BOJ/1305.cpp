#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
string T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> T;
	vector<int> pi(N + 1);
	int idx = 1, m = 0;

	while ((idx + m) <= N) {
		if (T[idx + m] == T[m]) {
			m++;
			pi[idx + m] = m;
		}
		else if (m) {
			idx += m - pi[m];
			m = pi[m];
		}
		else
			idx++;
	}
	cout << N - pi[N];
}