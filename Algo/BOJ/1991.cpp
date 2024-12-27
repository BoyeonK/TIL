#include <iostream>
#include <vector>
#include <string>

using namespace std;

inline char C(int i) {
	return char(i + 65);
}

inline int I(char c) {
	return int(c - 65);
}

int* tr = new int[26 * 2];
string pre, in, pos;

void dfs(int i) {
	pre = pre + C(i);
	if (tr[2 * i] >= 0) 
		dfs(tr[2 * i]);
	in = in + C(i);
	if (tr[2 * i + 1] >= 0)
		dfs(tr[2 * i + 1]);
	pos = pos + C(i);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, R;
	char a, b, c;
	cin >> N;
	fill_n(tr, 26 * 2, 0);
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		R = I(a);
		tr[2 * R] = I(b);
		tr[2 * R + 1] = I(c);
	}
	
	dfs(0);
	cout << pre << '\n' << in << '\n' << pos << endl;
}