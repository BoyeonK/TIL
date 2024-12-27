#include <iostream>
#include <cmath>

int main() {
	int N, ss = 0, cnt = 0;
	bool asdf;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> ss;
		if (ss == 2) cnt += 1;
		else if (ss > 2 && ss % 2) {
			asdf = true;
			for (int j = 1; sqrt(ss) >= (2 * j + 1); j++) if (!(ss % (2 * j + 1))) asdf = false;
			if (asdf) cnt += 1;
		}
	}
	std::cout << cnt;
}