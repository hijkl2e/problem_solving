#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	int K{}, Q{};
	cin >> N >> K >> Q;
	while (Q--) {
		ll x{}, y{};
		cin >> x >> y;
		if (K == 1) {
			cout << abs(x - y) << "\n";
			continue;
		}
		ll ans{};
		while (x != y) {
			if (x > y) {
				swap(x, y);
			}
			y = (y + K - 2) / K;
			++ans;
		}
		cout << ans << "\n";
	}
	return 0;
}
