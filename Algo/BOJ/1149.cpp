#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, r, g, b, R[2]{}, G[2]{}, B[2]{}, mnm=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> r >> g >> b;
		R[0] = R[1];
		G[0] = G[1];
		B[0] = B[1];
		R[1] = r + min(G[0], B[0]);
		G[1] = g + min(R[0], B[0]);
		B[1] = b + min(R[0], G[0]);
	}
	cout << min(R[1], min(G[1], B[1]));
}