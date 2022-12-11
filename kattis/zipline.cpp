#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll w, g, h;

double f(double x) {
	return sqrt(x * x + g * g) + sqrt((w - x) * (w - x) + h * h);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		ll r{};
		cin >> w >> g >> h >> r;
		g -= r;
		h -= r;
		double lo = 0, hi = w;
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
		cout << sqrt(w * w + (h - g) * (h - g)) << " " << f(lo) << "\n";
	}
	return 0;
}
