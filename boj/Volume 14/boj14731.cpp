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
	int N{};
	cin >> N;
	ll ans{};
	while (N--) {
		ll a{}, b{};
		cin >> a >> b;
		ans += a * b % MOD * pow(2LL, b - 1) % MOD;
	}
	ans %= MOD;
	cout << ans << "\n";
	return 0;
}
