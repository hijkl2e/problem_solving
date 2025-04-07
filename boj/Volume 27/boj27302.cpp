#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

vector<ll> fact, ifact;

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
	return fact[x] * ifact[x - y] % MOD * ifact[y] % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, K{};
	cin >> N >> K;
	N = min(N, K);
	fact.resize(K + 1);
	fact[0] = 1;
	for (int i = 1; i <= K; ++i) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	ifact.resize(K + 1);
	ifact[K] = pow(fact[K], MOD - 2);
	for (int i = K - 1; i >= 0; --i) {
		ifact[i] = (i + 1) * ifact[i + 1] % MOD;
	}
	ll ans{};
	for (int i = 1; i <= N; ++i) {
		ans += nCr(K, i);
	}
	ans = (ans % MOD + MOD) % MOD;
	cout << ans << "\n";
	return 0;
}
