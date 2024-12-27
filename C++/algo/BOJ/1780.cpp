#include <iostream>
#include <vector>

using namespace std;

int pp[2187][2187], ons = 0, zrs = 0, mns = 0;

void fnsslv(int k) {
	switch (k) {
	case(1):
		ons += 1;
		break;
	case(0):
		zrs += 1;
		break;
	case(-1):
		mns += 1;
		break;
	}
}

void slv(int xi, int yi, int ln) {
	int clr = pp[xi][yi];
	if (ln == 1) fnsslv(clr);
	else {
		for (int i = xi; i < xi + ln; i++) for (int j = yi; j < yi + ln; j++) {
			if (clr != pp[i][j]) {
				for (int i = xi; i < xi + ln; i+=ln/3) for (int j = yi; j < yi + ln; j+=ln/3) {
					slv(i, j, (ln / 3));
				}
				return;
			}
		}
		fnsslv(clr);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> pp[i][j];
	slv(0, 0, N);
	cout << mns << '\n' << zrs << '\n' << ons;
}