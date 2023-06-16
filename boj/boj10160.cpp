#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 9;

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
	ll N{}, K{};
	cin >> N >> K;
	vector<vector<ll>> dp(2, vector<ll>(8));
	dp[1][0] = 1;
	for (int i = 0; i < N; ++i) {
		copy(dp[1].begin(), dp[1].end(), dp[0].begin());
		ll x = accumulate(dp[0].begin(), dp[0].end() - 1, 0LL);
		dp[1][0] = ((K - 2) * x + dp[0][0]) % MOD;
		dp[1][1] = (x - dp[0][2] - dp[0][6]) % MOD;
		dp[1][2] = dp[0][1];
		dp[1][3] = dp[0][2];
		dp[1][4] = (dp[0][2] + dp[0][6]) % MOD;
		dp[1][5] = dp[0][3];
		dp[1][6] = dp[0][4];
		dp[1][7] = (dp[0][5] + dp[0][6] + K * dp[0][7]) % MOD;
	}
	ll ans = (pow(K, N) - dp[1][7] + MOD) % MOD;
	cout << ans << "\n";
	return 0;
}
