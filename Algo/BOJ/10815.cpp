#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M, inp, A, B=0, C=0;
	cin >> N;

	int* arrN = new int[N];
	for (int i = 0; i < N; i++) cin >> arrN[i];
	sort(arrN, arrN + N);

	cin >> M;
	int* ans = new int[M] {};
	vector<pair<int, int>> arrM;

	for (int i = 0; i < M; i++) {
		cin >> inp;
		arrM.push_back(make_pair(inp, i));
	}
	sort(arrM.begin(), arrM.end());

	for (int i = 0; i < M; i++) {
		A = arrM[i].first;
		B = C;
		while (B < N) {
			if (A < arrN[B]) break;
			else if (A == arrN[B]) {
				ans[arrM[i].second] = 1;
				break;
			}
			else C += 1;
			B += 1;
		}
	}

	for (int i = 0; i < M; i++) {
		cout << ans[i] << ' ';
	}
}