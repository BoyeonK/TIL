#include <iostream>
#include <vector>

using namespace std;

bool rr[9][10];
bool cc[9][10];
bool rc[9][10];
int arr[9][9];
vector<pair<int, int>> zeros;
int mxdp;
bool ee = false;


void sdk(int dp) {
	if (ee) return;
	else if (dp == mxdp) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
		ee = true;
		return;
	}
	int row = zeros[dp].first;
	int col = zeros[dp].second;
	for (int i = 1; i < 10; i++) {
		if (rr[row][i]) continue;
		if (cc[col][i]) continue;
		if (rc[3 * (row / 3) + col / 3][i]) continue;
		rr[row][i] = true;
		cc[col][i] = true;
		rc[3 * (row / 3) + col / 3][i] = true;
		arr[row][col] = i;
		sdk(dp + 1);
		rr[row][i] = false;
		cc[col][i] = false;
		rc[3 * (row / 3) + col / 3][i] = false;
	}
	arr[row][col] = 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> N;
			arr[i][j] = N;
			if (N == 0) zeros.push_back(make_pair(i, j));
			else {
				rr[i][N] = true;
				cc[j][N] = true;
				rc[3 * (i / 3) + j / 3][N] = true;
			}
		}
	}
	mxdp = zeros.size();
	sdk(0);
}