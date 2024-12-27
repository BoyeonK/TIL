#include <iostream>
#include <utility>

using namespace std;

pair<int, int> giyak(pair<int, int> num) {
	int min = (num.first > num.second) ? num.second : num.first;
	for (int i = 2; i <= min; i++) {
		if (num.first % i == 0 && num.second % i == 0) {
			return giyak(make_pair(num.first / i, num.second / i));
		}
	}
	return make_pair(num.first, num.second);
}

int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	pair<int, int> AB, CD, ans;
	AB = giyak(make_pair(A, B));
	CD = giyak(make_pair(C, D));
	A = AB.first;
	B = AB.second;
	C = CD.first;
	D = CD.second;
	ans = giyak(make_pair(A * D + B * C, B * D));
	cout << ans.first << ' ' << ans.second;
}