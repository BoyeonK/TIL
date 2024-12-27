#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T, n, r;
	long long a = 1;
	cin >> T;
	while (T--) {
		cin >> r >> n;
		if (r > n / 2) r = n - r;
		for (int i = 1; i <= r; i++) {
			a *= (n - i + 1);
			a = a/i;
		}
		cout << a << '\n';
		a = 1;
	}
}