#include <iostream>
#include <string>

using namespace std;
int main() {
	string wd;
	char a, b, c;
	getline(cin, wd);
	int j = 0;
	for (int i = 1; i < wd.size(); i++) {
		a = wd[i];
		b = wd[i - 1];
		c = (i > 1) ? wd[i - 2] : false;
		switch (a) {
		case '=': 
			if (b == 'c' or b == 's') j += 1; 
			else if (b == 'z') {
				if (c == 'd') {
					j += 2;
				}
				else j += 1;
			}
			break;
		case '-': if (b == 'c' or b == 'd') j += 1;
			break;
		case 'j': if (b == 'l' or b == 'n') j += 1;
			break;
		}
	}
	cout << wd.size() - j;
}