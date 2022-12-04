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
	return fact[x] * pow(fact[x - y] * fact[y] % MOD, MOD - 2) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	fact.resize(N + 1);
	fact[0] = 1;
	for (int i = 1; i <= N; ++i) {
		fact[i] = fact[i - 1] * i % MOD;
	}
	ll ans = fact[N] * pow(fact[N - K], MOD - 2) % MOD;
	for (int i = 1; i <= K; ++i) {
		ans += (i % 2 ? -1 : 1) * nCr(K, i) * fact[N - i] % MOD * pow(fact[N - K], MOD - 2) % MOD;
	}
	ans = (ans % MOD + MOD) % MOD;
	ans *= fact[N] * pow(fact[N - K], MOD - 2) % MOD;
	ans %= MOD;
	cout << ans << "\n";
	return 0;
}
