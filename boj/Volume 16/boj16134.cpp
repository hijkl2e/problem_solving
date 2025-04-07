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
	int N{}, R{};
	cin >> N >> R;
	vector<ll> fact(N + 1);
	fact[0] = 1;
	for (int i = 1; i <= N; ++i) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	ll ans = fact[N] * pow(fact[R] * fact[N - R] % MOD, MOD - 2) % MOD;
	cout << ans << "\n";
	return 0;
}
