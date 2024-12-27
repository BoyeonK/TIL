#include <iostream>
#include <vector>
#include <map>
#include <vector>
#include <string>

using namespace std;

map<string, string> fnet;
map<string, int> fnum;
vector<string> childnames;

string root(string fname) {
	if (fnet[fname] == fname) {
		for (auto& child : childnames)
			fnet[child] = fname;
		childnames.clear();
		return fname;
	}
	else {
		childnames.push_back(fname);
		return root(fnet[fname]);
	}
}

string findbyname(string fname, int& fn) {
	if (fnet.find(fname) == fnet.end()) {
		fnet[fname] = fname;
		fnum[fname] = 1;
		fn = 1;
		return fname;
	}
	else {
		fname = root(fname);
		fn = fnum[fname];
		return fname;
	}
}

void merge(string fl, string fr) {
	int fln, frn;
	fl = findbyname(fl, fln);
	fr = findbyname(fr, frn);
	if (fl != fr) {
		fnet[fr] = fl;
		fnum[fl] = fln + frn;
		cout << fln + frn << '\n';
	}
	else
		cout << fln << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, N;
	string fl, fr;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++){
			cin >> fl >> fr;
			merge(fl, fr);
		}
		fnet.clear();
		fnum.clear();
	}
}