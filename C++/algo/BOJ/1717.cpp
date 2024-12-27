#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> upper(1000001);

int root(int a) {
	int b = upper[a];
	int c = upper[b];
	if (a == b)
		return a;
	else {
		if (b == c)
			return b;
		else {
			upper[a] = c;
			return root(c);
		}
	}
}

void attach(int a, int b) {
	a = root(a);
	b = root(b);
	if (a != b) {
		upper[a] = b;
	}
}

void isInclude(int a, int b) {
	string ans;
	ans = (root(a) == root(b)) ? "YES" : "NO";
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, odr, a, b;
	cin >> n >> m;
	string ans;
	for (int i = 0; i <= n; i++)
		upper[i] = i;
	for (int i = 0; i < m; i++) {
		cin >> odr >> a >> b;
		if (odr)
			isInclude(a, b);
		else
			attach(a, b);
	}
}