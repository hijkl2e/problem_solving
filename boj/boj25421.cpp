#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 987654321;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<ll>> dp(N + 1, vector<ll>(10));
	fill(dp[1].begin() + 1, dp[1].end(), 1);
	for (int i = 2; i <= N; ++i) {
		for (int j = 1; j < 10; ++j) {
			for (int k = -2; k < 3; ++k) {
				int x = j + k;
				if (0 < x && x < 10) {
					dp[i][j] += dp[i - 1][x];
				}
			}
			dp[i][j] %= MOD;
		}
	}
	ll ans = accumulate(dp[N].begin(), dp[N].end(), 0LL) % MOD;
	cout << ans << "\n";
	return 0;
}
