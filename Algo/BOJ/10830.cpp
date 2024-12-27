#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	long long B;
	cin >> N >> B;
	vector<int**> Bt;
	vector<bool> bts;
	int** ac = new int* [N];
	int** E = new int* [N];
	int** temp = new int* [N];
	for (int i = 0; i < N; i++) { 
		ac[i] = new int[N];
		E[i] = new int[N];
		temp[i] = new int[N] {};
	}
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		cin >> ac[i][j];
		if (i == j) E[i][j] = 1;
		else E[i][j] = 0;
	}

	while (B) {
		if (B % 2) bts.push_back(true);
		else bts.push_back(false);
		B /= 2;
	}

	for (auto tf : bts) {
		if (tf) {
			for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) for (int k = 0; k < N; k++) {
				temp[i][j] += E[i][k] * ac[k][j];
			}
			for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
				E[i][j] = (temp[i][j]) % 1000;
				temp[i][j] = 0;
			}
		}
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) for (int k = 0; k < N; k++) {
			temp[i][j] += ac[i][k] * ac[k][j];
		}
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
			ac[i][j] = (temp[i][j]) % 1000;
			temp[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << E[i][j] << ' ';
		}
		cout << '\n';
	}
}