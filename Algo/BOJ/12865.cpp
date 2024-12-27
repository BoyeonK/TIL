#include <iostream>
#define max(a, b) (a>b) ? a:b

using namespace std;

int main() {
	int N, wt, W, V, mxm=0;
	cin >> N >> wt;
	int* pr = new int[wt + 1] { 0, };
	int* cr = new int[wt + 1] { 0, };
	for (int i = 0; N > i; i++) {
		cin >> W >> V;
		for (int j = 1; wt - W >= j; j++) {
			if (pr[j]) cr[j + W] = max(pr[j + W], pr[j] + V);
		}
		cr[W] = (cr[W] > V) ? cr[W] : V;
		for (int j = W; wt >= j; j++) pr[j] = cr[j];
	}
	for (int i = 0; wt >= i; i++) {
		mxm = max(mxm, cr[i]);
	}
	cout << mxm;
}