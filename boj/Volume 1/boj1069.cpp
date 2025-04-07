#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{}, y{}, d{}, t{};
	cin >> x >> y >> d >> t;
	d = max(d, t);
	double z = sqrt(x * x + y * y);
	int q = z / d;
	double ans = min({max(q + 1, 2) * t * 1.0, q * (t - d) + z, (q + 1) * (t + d) - z});
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
