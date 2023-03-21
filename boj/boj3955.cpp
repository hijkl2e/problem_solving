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
		ll K{}, C{};
		cin >> K >> C;
		if (gcd(K, C) > 1 || (K == 1000000000 && C == 1)) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		ll ans = K == 1 || C == 1 ? K + 1 : mod_inv(C, K);
		cout << ans << "\n";
	}
	return 0;
}
