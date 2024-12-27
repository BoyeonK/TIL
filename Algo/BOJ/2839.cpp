#include <iostream>

int main() {
	int N, quo, rem, ans;
	std::cin >> N;
	quo = N / 5;
	rem = N % 5;
	while (rem % 3) {
		if (quo) {
			quo -= 1;
			rem += 5;
		}
		else break;
	}
	ans = (rem % 3) ? -1 : quo + rem / 3;
	std::cout << ans;
}