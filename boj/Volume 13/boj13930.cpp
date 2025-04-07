#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{}, y{}, N{};
	cin >> x >> y >> N;
	double z = y;
	while (N--) {
		int l{}, u{};
		double f{};
		cin >> l >> u >> f;
		z += (u - l) * (f - 1);
	}
	double ans = x / z;
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
