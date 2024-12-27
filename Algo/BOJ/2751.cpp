#include <iostream>

using namespace std;

void swt(int arr[], int x, int y) {
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void heap(int arr[], int i, int len) {
	int l = 2 * i + 1;
	int r = l + 1;
	if (r < len && arr[r] > arr[l] && arr[r] > arr[i]) {
		swt(arr, r, i);
		heap(arr, r, len);
	}
	if (l == len - 1 && arr[l] > arr[i]) {
		swt(arr, l, i);
		heap(arr, l, len);
	} else if (l < len && arr[l] > arr[r] && arr[l] > arr[i]) {
		swt(arr, l, i);
		heap(arr, l, len);
	}
}

int main() {
	int N, inp, d, u;
	std::cin >> N;
	int* arr = new int[N] {};

	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
		d = i;
		while (d) {
			u = (d - 1) / 2;
			if (arr[d] > arr[u]) swt(arr, d, u);
			d = u;
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		swt(arr, 0, i);
		heap(arr, 0, i);
	}

	for (int i = 0; i < N; i++) {
		std::cout << arr[i] << '\n';
	}
}