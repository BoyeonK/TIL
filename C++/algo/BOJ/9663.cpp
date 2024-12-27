#include <iostream>

using namespace std;

int ans = 0;

bool isvalar(int* ar, int dp) {
	for (int j = 0; j < dp; j++) {
		if((ar[dp]==ar[j]) or (dp-j == abs(ar[j]-ar[dp]))) return false;
	}
	return true;
}

void Qn(int*ar, int dp, int N) {
	if (dp == N) ans += 1;
	else {
		for (int i = 0; i < N; i++) {
			ar[dp] = i;
			if (isvalar(ar,dp)) {	
				Qn(ar, dp + 1, N);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int* ar = new int[15];
	Qn(ar, 0, N);
	cout << ans;
}