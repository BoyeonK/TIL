#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C, inp;
vector<int> arr;
vector<int> R;
vector<int> L;

void dfs(int S, int E, vector<int>&comb, int sum) {
	if (sum > C) return;
	else if (S > E) {
		comb.push_back(sum);
	}
	else {
		dfs(S + 1, E, comb, sum);
		dfs(S + 1, E, comb, sum + arr[S]);
	}
}

int main() {
	cin >> N >> C;
	arr.resize(N, 0);
	for (int i = 0; i < N; i++) cin >> arr[i];
	dfs(0, (N - 1) / 2, L, 0);
	dfs((N - 1) / 2 + 1, N - 1, R, 0);
	sort(L.begin(), L.end());
	sort(R.begin(), R.end());
	int tt = 0;
	int cases = R.size();
	for (int lr : L) {
		while (R.back()+lr > C) {
			R.pop_back();
			cases--;
		}
		tt += cases;
	}
	cout << tt;
}