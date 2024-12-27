#include <iostream>
#include <string>

using namespace std;
int main() {
	string a, c;
	double b;
	double pnt = 0;
	int sub = 0;
	while (cin >> a >> b >> c) {
		sub += b;
		switch (c[0]) {
		case 'A':
			pnt += 4*b;
			if (c[1] == '+') pnt += 0.5 * b;
			break;
		case 'B':
			pnt += 3*b;
			if (c[1] == '+') pnt += 0.5*b;
			break;
		case 'C':
			pnt += 2*b;
			if (c[1] == '+') pnt += 0.5*b;
			break;
		case 'D':
			pnt += 1*b;
			if (c[1] == '+') pnt += 0.5*b;
			break;
		case 'P':
			sub-=b;
		}
	}
	cout << pnt / sub;
}