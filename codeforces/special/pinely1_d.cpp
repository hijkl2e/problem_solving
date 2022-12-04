#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

vector<ll> fact;

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

ll nCr(ll x, ll y) {
	return x >= y ? fact[x] * pow(fact[x - y] * fact[y] % MOD, MOD - 2) % MOD : 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, K{};
	cin >> N >> K;
	fact.resize(N + 1);
	fact[0] = 1;
	for (int i = 1; i <= N; ++i) {
		fact[i] = fact[i - 1] * i % MOD;
	}
	if (K == 0) {
		cout << pow(3LL, N) << "\n";
		return 0;
	}
	ll ans{};
	for (int i = 1; i <= N; ++i) {
		ans += pow(3LL, N - i) * nCr(K - 1, (i - 1) / 2) % MOD * nCr(N - K, i / 2) % MOD;
	}
	ans %= MOD;
	cout << ans << "\n";
	return 0;
}
