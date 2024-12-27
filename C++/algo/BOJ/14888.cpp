#include <iostream>

using namespace std;

int* op = new int[4];
int* arr = new int[11];
int mxdp, mnm = 1000000000, mxm = -1000000000;

void sol(int n, int dp) {
	if (dp >= mxdp) {
		if (n > mxm) mxm = n;
		if (n < mnm) mnm = n;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i]) {
			op[i] -= 1;
			switch (i) {
			case(0):
				sol(n + arr[dp], dp + 1);
				break;
			case(1):
				sol(n - arr[dp], dp + 1);
				break;
			case(2):
				sol(n * arr[dp], dp + 1);
				break;
			case(3):
				sol(n / arr[dp], dp + 1);
				break;
			}
			op[i] += 1;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int nm;
	cin >> mxdp;
	for (int i = 0; i < mxdp; i++) {
		cin >> nm;
		arr[i] = nm;
	}
	for (int i = 0; i < 4; i++) {
		cin >> nm;
		op[i] = nm;
	}
	sol(arr[0], 1);
	cout << mxm << '\n' << mnm;
}