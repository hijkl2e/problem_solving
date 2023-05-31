#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<vector<ll>> dp(N, vector<ll>(K + 1));
	fill(dp[0].begin() + 1, dp[0].end(), 1);
	for (int i = 1; i < N; ++i) {
		ll x = accumulate(dp[i - 1].begin(), dp[i - 1].end(), 0LL) % MOD;
		fill(dp[i].begin() + 1, dp[i].end(), x);
		for (int j = 1; j <= K; ++j) {
			for (int k = 2 * j; k <= K; k += j) {
				dp[i][j] -= dp[i - 1][k];
			}
			dp[i][j] = (dp[i][j] % MOD + MOD) % MOD;
		}
	}
	ll ans = accumulate(dp[N - 1].begin(), dp[N - 1].end(), 0LL) % MOD;
	cout << ans << "\n";
	return 0;
}
