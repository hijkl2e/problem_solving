#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int d1{}, d2{}, x{};
	cin >> d1 >> d2 >> x;
	if (d1 > d2) {
		swap(d1, d2);
	}
	double ans = d1 * d2 * 100.0 / (d1 * x + d2 * (100 - x));
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
