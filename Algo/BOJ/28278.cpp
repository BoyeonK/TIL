#include <iostream>
#include <deque>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, odr, ip, op;
	cin >> N;
	deque<int> stk;
	for (int i = 0; i < N; i++) {
		cin >> odr;
		switch (odr) {
		case(1):
			cin >> ip;
			stk.push_back(ip);
			break;
		case(2):
			if (stk.size() != 0) {
				op = stk.back();
				stk.pop_back();
			}
			else {
				op = -1;
			}
			cout << op << '\n';
			break;
		case(3):
			cout << stk.size() << '\n';
			break;
		case(4):
			op = (stk.empty()) ? 1 : 0;
			cout << op << '\n';
			break;
		case(5):
			op = (stk.empty()) ? -1 : stk.back();
			cout << op << '\n';
			break;
		}
	}
}