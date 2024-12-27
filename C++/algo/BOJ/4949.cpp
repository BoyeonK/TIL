#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	string wd;
	char c;
	deque<char> brk;
	bool harmony = true;

	while (getline(cin, wd)) {
		for (int i = 0; i < wd.size(); i++) {
			c = wd[i];
			if (c == '(') brk.push_back(c);
			else if (c == '[') brk.push_back(c);
			else if (c == ')') {
				if (!brk.empty()) {
					if (brk.back() == '(') brk.pop_back();
					else harmony = false;
				}
				else harmony = false;
			}
			else if (c == ']') {
				if (!brk.empty()) {
					if (brk.back() == '[') brk.pop_back();
					else harmony = false;
				}
				else harmony = false;
			}
			else if (c == '.' && wd.size() > 1) {
				if (brk.size()) harmony = false;
				if (harmony) cout << "yes" << '\n';
				else cout << "no" << '\n';
			}
		}
		harmony = true;
		brk.clear();
	}
}