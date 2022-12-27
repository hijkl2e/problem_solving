#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

ll pow(ll x, ll y) {
	ll ret = 1;
	while (y) {
		if (y % 2) {
			ret = ret * x % MOD;
		}
		x = x * x % MOD;
		y /= 2;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<ll> fact(2000001);
	fact[0] = 1;
	for (int i = 1; i < fact.size(); ++i) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	int Q{};
	cin >> Q;
	while (Q--) {
		int a{}, b{};
		cin >> a >> b;
		ll ans = fact[a + b - 1] * pow(fact[a] * fact[b] % MOD, MOD - 2) % MOD;
		cout << ans << "\n";
	}
	return 0;
}
