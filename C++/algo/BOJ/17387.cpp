#include <iostream>

using namespace std;

int main() {
	double x1, x2, x3, x4, y1, y2, y3, y4, temp, ans = 0;
	double a12 = 0, a34 = 0;
	double Ly = 0, Ry = 0;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	if (x1 > x2) {
		temp = y1;
		y1 = y2;
		y2 = temp;
		temp = x1;
		x1 = x2;
		x2 = temp;
	}
	if (x3 > x4) {
		temp = y3;
		y3 = y4;
		y4 = temp;
		temp = x3;
		x3 = x4;
		x4 = temp;
	}
	if (x1 != x2) 
		a12 = (y1 - y2) / (x1 - x2);
	if (x3 != x4)
		a34 = (y3 - y4) / (x3 - x4);

	if (x3 > x2 or x1 > x4) 
		ans = 0;
	else {
		if (x1 > x3)
			Ly = y3 + a34 * (x1 - x3) - y1;
		else
			Ly = y3 - (y1 + a12 * (x3 - x1));

		if (x2 > x4)
			Ry = y4 - (y2 - a12 * (x2 - x4));
		else
			Ry = y4 - a34 * (x4 - x2) - y2;

		double epsilon = 0.0001;
		if (abs(Ly) < epsilon or abs(Ry) < epsilon)
			ans = 1;
		else if ((Ly <= 0 and Ry >= 0) or (Ly >= 0 and Ry <= 0))
			ans = 1;
	}
	cout << ans;
}