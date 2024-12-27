#include <iostream>

using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M, inp;
	cin >> N;
	int* arr = new int[20000000]{};
	for (int i = 0; i < N; i++) {
		cin >> inp;
		arr[inp + 10000000] += 1;
	}
	cin >> M;
	for (int j = 0; j < M; j++) {
		cin >> inp;
		cout << arr[inp + 10000000] << ' ';
	}
}