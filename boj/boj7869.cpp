#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double x1{}, y1{}, r1{}, x2{}, y2{}, r2{};
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	if (r1 < r2) {
		swap(x1, x2);
		swap(y1, y2);
		swap(r1, r2);
	}
	double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	double ans{};
	if (r1 + r2 < d + EPS) {
		ans = 0;
	} else if (d < r1 - r2 + EPS) {
		ans = PI * r2 * r2;
	} else {
		double z = (r1 * r1 - r2 * r2 + d * d) / (2 * d);
		ans = acos(z / r1) * r1 * r1 + acos((d - z) / r2) * r2 * r2 - d * sqrt(r1 * r1 - z * z);
	}
	cout << fixed << setprecision(3);
	cout << ans << "\n";
	return 0;
}
