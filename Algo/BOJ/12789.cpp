#include <iostream>
#include <deque>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, num, seq = 1;
	cin >> N;
	deque<int> NoYangSim;
	while (N--) {
		cin >> num;
		if (num == seq) seq++;
		else NoYangSim.push_back(num);
		while (!NoYangSim.empty() && NoYangSim.back() == seq) {
			seq++;
			NoYangSim.pop_back();
		}
	}
	if (NoYangSim.empty()) cout << "Nice";
	else cout << "Sad";
}