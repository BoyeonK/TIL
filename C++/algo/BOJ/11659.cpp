#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, cnt, inp, nxt, i, j, tt = 0;
	cin >> N >> cnt;
	vector<int> arr{ 0 };
	for (int a = 0; a < N; a++) {
		cin >> inp;
		nxt = inp + arr.back();
		arr.push_back(nxt);
	}
	while (cnt--) {
		cin >> i >> j;
		tt = arr[j] - arr[i-1];
		cout << tt << '\n';
		tt = 0;
	}
}