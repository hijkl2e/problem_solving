#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double x{}, y{};
	while (cin >> x >> y) {
		int ans{};
		if (y > 0) {
			ans = x > 0 ? 1 : x < 0 ? 2 : 0;
		} else if (y < 0) {
			ans = x < 0 ? 3 : x > 0 ? 4 : 0;
		}
		if (ans) {
			cout << "Q" << ans << "\n";
		} else {
			cout << "AXIS\n";
		}
	}
	return 0;
}
