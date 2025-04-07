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

vector<ll> fact, ifact;

ll nCr(int n, int r) {
	return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{};
	cin >> M;
	fact.resize(2 * M + 1);
	fact[0] = 1;
	for (int i = 1; i < fact.size(); ++i) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	ifact.resize(2 * M + 1);
	ifact.back() = pow(fact.back(), MOD - 2);
	for (int i = ifact.size() - 2; i >= 0; --i) {
		ifact[i] = (i + 1) * ifact[i + 1] % MOD;
	}
	ll ans{};
	for (int i = 3; i <= M; ++i) {
		ans = (ans + nCr(2 * i, i)) % MOD;
	}
	cout << ans << "\n";
	return 0;
}
