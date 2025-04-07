#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll x{}, y{}, w{}, s{};
	cin >> x >> y >> w >> s;
	if (x > y) {
		swap(x, y);
	}
	ll ans = w * (x + y);
	ans = min(ans, s * x + w * (y - x));
	if ((y - x) % 2) {
		ans = min(ans, s * (y - 1) + w);
	} else {
		ans = min(ans, s * y);
	}
	cout << ans << "\n";
	return 0;
}
