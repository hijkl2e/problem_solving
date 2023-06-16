#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int d{}, s{};
	cin >> d >> s;
	double lo = 0, hi = 1e9;
	for (int i = 0; i < 100; ++i) {
		double mid = (lo + hi) / 2;
		if (cosh(d / (2 * mid)) > 1 + s / mid) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	double ans = 2 * hi * sinh(d / (2 * hi));
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
