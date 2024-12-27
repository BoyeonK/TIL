#include <iostream>
#include <string>

using namespace std;
int main() {
	string c;
	cin >> c;
	int arr[26] = { 0, };
	for (int i = 0; i < c.size(); i++) {
		if (c[i] >= 97) arr[c[i] - 97] = arr[c[i] - 97] + 1;
		else arr[c[i] - 65] = arr[c[i] - 65] + 1;
	}
	int mxm = 0, j = 0;
	bool dup = false;
	for (int i = 0; i < 26; i++) {
		if (arr[i] > mxm) {
			mxm = arr[i];
			j = i;
			dup = false;
		}
		else if (arr[i] == mxm) dup = true;
	}
	char a = (dup) ? '?' : char(65 + j);
	cout << a;
}