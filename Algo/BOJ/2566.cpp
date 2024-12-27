#include <iostream>

int main() {
	int i = 9, mxm = 0, j = 0, pnt;
	while (std::cin >> pnt) {
		if (pnt >= mxm) {
			j = i;
			mxm = pnt;
		}
		i++;
	}
	std::cout << mxm << '\n' << j / 9 << ' ' << j % 9 +1;
}