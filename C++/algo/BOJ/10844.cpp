#include <iostream>

int main() {
	long N, tt = 0, dp[2][10]{};
	for (int i = 1; i < 10; i++) dp[0][i] = 1;
	std::cin >> N;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < 9; j++) dp[1][j] = (dp[0][j - 1] + dp[0][j + 1]) % 1000000000;
		dp[1][0] = dp[0][1];
		dp[1][9] = dp[0][8];
		for (int j = 0; j < 10; j++) dp[0][j] = dp[1][j];
	}
	for (int i = 0; i < 10; i++) tt += dp[0][i];
	std::cout << tt % 1000000000;
}