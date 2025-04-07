#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double x{}, y{}, c{};
	cin >> x >> y >> c;
	double lo = 0, hi = min(x, y);
	for (int i = 0; i < 100; ++i) {
		double mid = (lo + hi) / 2;
		double h1 = sqrt(x * x - mid * mid);
		double h2 = sqrt(y * y - mid * mid);
		double z = h1 * h2 / (h1 + h2);
		if (z < c) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout << fixed << setprecision(10);
	cout << lo << "\n";
	return 0;
}
