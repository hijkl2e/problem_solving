#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

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

ii solve(ll N) {
	if (N == 1) {
		return {1, 0};
	}
	auto [x, y] = solve(N / 2);
	ii ret{x * (x + 2 * y) % MOD, (x * x + y * y) % MOD};
	if (N % 2) {
		ret = {(ret.first + ret.second) % MOD, ret.first};
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, K{};
	cin >> N >> K;
	vector<vector<ll>> nCr(K + 1, vector<ll>(K + 1));
	for (int i = 1; i <= K; ++i) {
		nCr[i][0] = nCr[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % MOD;
		}
	}
	ii fibo = solve(N + 2);
	N %= MOD;
	vector<ll> dp(K + 1);
	dp[0] = fibo.first + fibo.second - 2;
	for (int i = 1; i <= K; ++i) {
		dp[i] = (fibo.first * pow(N, 1LL * i) + fibo.second * pow(N + 1, 1LL * i) - 1) % MOD;
		for (int j = i - 1; j >= 0; j -= 2) {
			dp[i] -= 2 * nCr[i][j] * dp[j] % MOD;
		}
		dp[i] %= MOD;
	}
	ll ans = (dp[K] + MOD) % MOD;
	cout << ans << "\n";
	return 0;
}
