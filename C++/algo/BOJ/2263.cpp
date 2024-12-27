#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, int>> tr(100001);
vector<int> IO(100000);
vector<int> OI(100001);
vector<int> PO(100000);

int seq;

int maketree(int l, int r) {
	if (l > r) return 0;
	int root = PO[seq];
	int idx = OI[root];
	seq--;
	if (l != r) {
		tr[root].second = maketree(idx + 1, r);
		tr[root].first = maketree(l, idx - 1);
	}
	return root;
}

void prt(int root) {
	cout << root << " ";
	if (tr[root].first)
		prt(tr[root].first);
	if (tr[root].second)
		prt(tr[root].second);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, inp, top;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> inp;
		IO[i] = inp;
		OI[inp] = i;
	}
	for (int i = 0; i < N; i++)
		cin >> PO[i];

	top = PO[N - 1];
	seq = N - 1;
	maketree(0, N - 1);
	prt(top);
}