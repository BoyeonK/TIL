#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M, pknum;
	string pkname;
	vector<string> dogam;
	map<string, int> magod;
	dogam.push_back("DasomLee");

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> pkname;
		magod[pkname] = i;
		dogam.push_back(pkname);
	}
	for (int i = 0; i < M; i++) {
		cin >> pkname;
		if (isdigit(pkname[0])) { 
			pknum = stoi(pkname);
			cout << dogam[pknum] << '\n';
		}
		else {
			cout << magod[pkname] << '\n';
		}
	}
}