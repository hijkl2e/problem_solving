#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		ll N{}, k{}, g{};
		cin >> N >> k >> g;
		ll x = k * g;
		ll ans = min((g - 1) / 2 * (N - 1), x);
		x = (x - ans) % g;
		ans += x - (x > (g - 1) / 2 ? g : 0);
		cout << ans << "\n";
	}
	return 0;
}
