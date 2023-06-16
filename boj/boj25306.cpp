#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(ll x) {
	ll ret{};
	for (ll i = x / 4 * 4; i <= x; ++i) {
		ret ^= i;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll a{}, b{};
	cin >> a >> b;
	ll ans = solve(b) ^ solve(a - 1);
	cout << ans << "\n";
	return 0;
}
