#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double x{}, p{};
	cin >> x >> p;
	x /= 100, p /= 100;
	double r = (1 - p) / p;
	double ans{};
	bool flag = p > 0;
	for (int w = 1, bl = 1; flag; ++w) {
		flag = false;
		double prev{};
		for (int l = bl;; ++l) {
			double E = (1 - pow(r, w)) / (pow(r, w) - pow(r, -l)) * (w + l * (1 - x)) + w;
			if (ans < E) {
				ans = E;
				bl = l;
				flag = true;
			} else if (prev > E) {
				break;
			}
			prev = E;
		}
	}
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
