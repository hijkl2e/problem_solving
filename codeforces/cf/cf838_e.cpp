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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	ll ans{}, nCr = 1;
	for (ll i = 1; i < N; ++i) {
		ans += (i % 2 == 1 ? -1 : 1) * nCr * i % MOD * (N - i) % MOD
				* pow(i, i - 2) % MOD * pow(N - i, N - i - 2) % MOD;
		nCr = nCr * (N - i - 1) % MOD * pow(i, MOD - 2) % MOD;
	}
	ans = (ans % MOD + MOD) % MOD;
	cout << ans << "\n";
	return 0;
}
