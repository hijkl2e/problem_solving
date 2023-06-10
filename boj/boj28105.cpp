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
	return y >= 0 ? fact[x] * ifact[y] % MOD * ifact[x - y] % MOD : 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, X{}, Y{};
	cin >> N >> X >> Y;
	if (X > Y) {
		swap(X, Y);
	}
	fact.resize(2 * N + 1);
	fact[0] = 1;
	for (int i = 1; i < fact.size(); ++i) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	ifact.resize(2 * N + 1);
	ifact.back() = pow(fact.back(), MOD - 2);
	for (int i = ifact.size() - 2; i >= 0; --i) {
		ifact[i] = (i + 1) * ifact[i + 1] % MOD;
	}
	ll ans{};
	for (int i = (X - 1) % 2; i < Y - X; i += 2) {
		int j = Y - X - i - 1;
		int r1 = (X - i - 1) / 2;
		int l2 = (2 * N - Y - j) / 2;
		ans += (nCr(X - 1, r1) - nCr(X - 1, r1 - 1)) * nCr(Y - X - 1, i) % MOD
				* (nCr(2 * N - Y, l2) - nCr(2 * N - Y, l2 - 1)) % MOD;
	}
	ans = (ans % MOD + MOD) % MOD;
	cout << ans << "\n";
	return 0;
}
