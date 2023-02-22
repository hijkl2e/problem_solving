#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

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

ll nCr(ll x, ll y) {
	return fact[x] * ifact[x - y] % MOD * ifact[y] % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, p{}, q{};
	cin >> N >> p >> q;
	fact.resize((N + 3) / 2);
	fact[0] = 1;
	for (int i = 1; i < fact.size(); ++i) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	ifact.resize((N + 3) / 2);
	ifact.back() = pow(fact.back(), MOD - 2);
	for (int i = ifact.size() - 2; i >= 0; --i) {
		ifact[i] = (i + 1) * ifact[i + 1] % MOD;
	}
	vector<ll> A((N + 1) / 2);
	for (int i = 0; i < A.size(); ++i) {
		A[i] = nCr((N - 1) / 2, i);
		A[i] = A[i] * A[i] % MOD;
	}
	ll x = p * pow(q, MOD - 2) % MOD;
	for (ll i = 0, y = 1; i < A.size(); ++i) {
		A[i] = A[i] * y % MOD;
		y = x * x % MOD * y % MOD;
	}
	for (ll i = A.size() - 1, y = 1; i >= 0; --i) {
		A[i] = A[i] * y % MOD;
		y = (1 - x) * (1 - x) % MOD * y % MOD;
	}
	ll k = accumulate(A.begin(), A.end(), 0LL) % MOD;
	ll ans = (499122177 * (1 - k + MOD) + k * x) % MOD;
	cout << ans << "\n";
	return 0;
}
