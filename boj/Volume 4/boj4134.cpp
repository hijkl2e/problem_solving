#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		ll N{};
		cin >> N;
		N = max(N, 2LL);
		ll ans{};
		for (ll i = N;; ++i) {
			bool yes = true;
			for (ll j = 2; j * j <= i; ++j) {
				if (i % j == 0) {
					yes = false;
					break;
				}
			}
			if (yes) {
				ans = i;
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
