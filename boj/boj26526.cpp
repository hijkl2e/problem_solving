#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<vector<ll>> dp(N, vector<ll>(N));
	dp[1][1] = 1;
	for (int i = 2; i < N; ++i) {
		for (int j = max(i - K, 1); j < i; ++j) {
			ll val = dp[i - 1][j] - dp[max(i - K - 1, 0)][j];
			dp[i][j] = (dp[i - 1][j] + val) % MOD;
			dp[j][i] = (dp[j - 1][i] + val) % MOD;
		}
		dp[i][i] = dp[i - 1][i];
	}
	ll ans{};
	for (int i = N - K; i < N; ++i) {
		ans += dp[N - 1][i] - dp[N - K - 1][i];
	}
	ans = (ans % MOD + MOD) % MOD;
	cout << ans << "\n";
	return 0;
}
