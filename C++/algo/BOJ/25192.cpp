#include <iostream>
#include <map>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N, greet = 0;
	map<string, bool> GomGom;
	string nm;

	cin >> N;
	while (N--) {
		cin >> nm;
		if (nm == "ENTER") GomGom.clear();
		else if (!GomGom[nm]) {
			GomGom[nm] = true;
			greet += 1;
		}
	}
	cout << greet;
}