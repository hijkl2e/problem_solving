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

vector<ll> fact;

ll nCr(ll x, ll y) {
	return fact[x] * pow(fact[x - y] * fact[y] % MOD, MOD - 2) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	fact.resize(N + M);
	fact[0] = 1;
	for (int i = 1; i < fact.size(); ++i) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	ll ans = 2 * nCr(N + M - 4, N - 2) % MOD * nCr(N + M - 3, N - 2) % MOD
				* pow(N - 1LL, MOD - 2) % MOD;
	cout << ans << "\n";
	return 0;
}
