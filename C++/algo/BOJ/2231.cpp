#include <iostream>

int main() {
	int N, tt, quo, ans = 0;
	std::cin >> N;
	for (int i = 1; i < N; i++) {
		tt = 0;
		quo = i;
		while (quo % 10) {
			tt += quo % 10;
			quo /= 10;
		}
		if (tt + i == N) {
			ans = i; 
			break;
		}
	}
	std::cout << ans;
}