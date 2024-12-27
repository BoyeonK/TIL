#include <iostream>
#include <deque>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int A, B, b, C, bt = 1073741824;
	long long ac = 1;
	deque<bool> bts;
	cin >> A >> B >> C;
	A = A % C;
	b = B;
	while (bt) {
		if (b >= bt) { 
			bts.push_front(true); 
			b -= bt;
		}
		else bts.push_front(false);
		bt /= 2;
	}
	long long* arr = new long long[bts.size()];
	arr[0] = A;
	for (int i = 1; i < bts.size(); i++) arr[i] = (arr[i - 1] * arr[i - 1]) % C;
	for (int i = 0; i < bts.size(); i++) if (bts[i]) ac = (ac * arr[i]) % C;
	cout << ac;
}