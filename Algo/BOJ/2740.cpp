#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M, K, at = 0;
	cin >> N >> M;
	int A[100][100]{}, B[100][100]{};
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)	cin >> A[i][j];

	cin >> M >> K;
	for (int i = 0; i < M; i++) for (int j = 0; j < K; j++) cin >> B[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < M; k++) at += A[i][k] * B[k][j];
			cout << at << ' ';
			at = 0;
		}
		cout << '\n';
	}
}