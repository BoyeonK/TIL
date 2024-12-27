#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<pair<int, int>> tr(1000001);
stack<int> S;
int now;

void sol(int N) {
	if (S.top() > N)
		tr[S.top()].first = N;
	else if (S.top() < N) {
		while (!S.empty() && S.top() < N) {
			now = S.top();
			S.pop();
		}
		tr[now].second = N;
	}
	S.push(N);
}

void prt(int root) {
	if (tr[root].first)
		prt(tr[root].first);
	if (tr[root].second)
		prt(tr[root].second);
	cout << root << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int inp, r;
	cin >> inp;
	r = inp;
	now = inp;
	S.push(r);
	while (cin >> inp) 
		sol(inp);
	prt(r);
}