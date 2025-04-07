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
	ll N{}, M{};
	cin >> N >> M;
	N = 1 << N;
	if (N < M) {
		cout << "1\n";
		return 0;
	}
	ll ans = 1;
	for (int i = 0; i < M; ++i) {
		ans = ans * (N - i) % MOD;
	}
	ans = ans * pow(pow(N, M), MOD - 2) % MOD;
	ans = (1 - ans + MOD) % MOD;
	cout << ans << "\n";
	return 0;
}
