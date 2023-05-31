#include <bits/stdc++.h>

using namespace std;

int ax, ay, az, bx, by, bz, cx, cy, cz;

double f(double p) {
	double x = (1 - p) * ax + p * bx;
	double y = (1 - p) * ay + p * by;
	double z = (1 - p) * az + p * bz;
	return sqrt((cx - x) * (cx - x) + (cy - y) * (cy - y) + (cz - z) * (cz - z));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> ax >> ay >> az >> bx >> by >> bz >> cx >> cy >> cz;
	double lo = 0, hi = 1;
	for (int i = 0; i < 100; ++i) {
		double d = (hi - lo) / 3;
		double m1 = lo + d;
		double m2 = hi - d;
		if (f(m1) > f(m2)) {
			lo = m1;
		} else {
			hi = m2;
		}
	}
	cout << fixed << setprecision(10);
	cout << f(lo) << "\n";
	return 0;
}
