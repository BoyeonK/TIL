#include <iostream>
#include <deque>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int nmr = 1000000007;
	long long B, kk, jj, kj, ks, js;
	deque<bool> mtd;
	cin >> B;
	if (B <= 1) { 
		cout << B;
		return 0;
	}
	while (B > 3) {
		if (B % 2) mtd.push_front(true);
		else mtd.push_front(false);
		B /= 2;
	}
	pair<long long, long long> ans{ B - 1, 1 };
	for (auto a : mtd) {
		kk = (ans.first * ans.first) % nmr;
		kj = (ans.first * ans.second) % nmr;
		jj = (ans.second * ans.second) % nmr;
		ks = (kk + 2 * kj) % nmr;
		js = (kk + jj) % nmr;
		if (a) {
			ans = make_pair((ks + js) % nmr, ks);
		}
		else {
			ans = make_pair(ks, js);
		}
	}
	cout << ans.first;
}