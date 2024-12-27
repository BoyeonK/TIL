#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	string stt;
	int N, f, e;
	char idx;
	int** acc = new int* [26];
	cin >> stt >> N;
	for (int i = 0; i < 26; i++) acc[i] = new int[stt.length() + 1]{};
	for (int i = 0; i < stt.length(); i++) {
		for (int j = 0; j < 26; j++) acc[j][i + 1] = acc[j][i];
		idx = stt[i];
		acc[idx - 97][i + 1] += 1;
	}
	while (N--) {
		cin >> idx >> f >> e;
		cout << (acc[idx - 97][e + 1] - acc[idx - 97][f]) << '\n';
	}
}