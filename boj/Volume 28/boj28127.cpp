#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int Q{};
	cin >> Q;
	while (Q--) {
		ll a{}, d{}, x{};
		cin >> a >> d >> x;
		int lo = 0, hi = 2e3;
		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;
			if (x > mid * a + mid * (mid - 1) / 2 * d) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		int ans_x = hi;
		int ans_y = x - (lo * a + lo * (lo - 1) / 2 * d);
		cout << ans_x << " " << ans_y << "\n";
	}
	return 0;
}
