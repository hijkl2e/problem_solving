#include <bits/stdc++.h>

using namespace std;

using ll = long long;

pair<ll, ll> ext_gcd(ll a, ll b) {
	if (b) {
		auto [x, y] = ext_gcd(b, a % b);
		return {y, x - (a / b) * y};
	} else {
		return {1, 0};
	}
}

ll mod_inv(ll a, ll mod) {
	return (ext_gcd(a, mod).first + mod) % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		ll a{}, b{}, d{};
		cin >> a >> b >> d;
		a |= b;
		ll c = (d - a % d) % d;
		ll e = (1 << 30) % d;
		ll g = gcd(e, d);
		if (c % g) {
			cout << "-1\n";
			continue;
		}
		a |= (c / g * mod_inv(e, d) % d) << 30;
		cout << a << "\n";
	}
	return 0;
}
