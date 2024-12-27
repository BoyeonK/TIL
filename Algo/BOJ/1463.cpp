#include <iostream>
#define min(a, b) (a > b) ? b : a;

int main() {
	int N;
	std::cin >> N;
	int* arr = new int[N + 1]{};
	for (int i = 2; i <= N; i++) {
		arr[i] = arr[i - 1];
		if (i % 2 == 0) arr[i] = min(arr[i / 2], arr[i]);
		if (i % 3 == 0) arr[i] = min(arr[i / 3], arr[i]);
		arr[i] += 1;
	}
	std::cout << arr[N];
}