#include <iostream>
#include <vector>

using namespace std;

int arr[20][20];
vector<int> stm, lkm;
int N, nm, mnm=1e9, cnt=0;
bool stt[20];

void teamify(int dp, int mx) {
	if (dp >= N / 2) {
		int stp = 0, lkp = 0, pt;
		stm.clear();
		lkm.clear();
		for (int i = 0; i < N; i++) {
			if (stt[i]) stm.push_back(i);
			else lkm.push_back(i);
		}
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				stp += arr[stm[i]][stm[j]];
				lkp += arr[lkm[i]][lkm[j]];
			}
		}
		pt = abs(stp - lkp);
		if (mnm > pt) mnm = pt;
		return;
	}
	for (int i = mx; i < N; i++) {
		stt[i] = true;
		teamify(dp + 1, i+1);
		stt[i] = false;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	teamify(0, 0);
	cout << mnm;
}