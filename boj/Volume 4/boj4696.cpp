#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double x{};
	while (cin >> x, x) {
		double y = 1, ans{};
		for (int i = 0; i < 5; ++i) {
			ans += y;
			y *= x;
		}
		cout << fixed << setprecision(2);
		cout << ans << "\n";
	}
	return 0;
}
