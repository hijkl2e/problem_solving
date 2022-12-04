#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<ll>> dp(100001, vector<ll>(3));
	dp[0][0] = 1;
	for (int i = 1; i < dp.size(); ++i) {
		if (i % 2) {
			dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		} else {
			dp[i][0] = (dp[i - 2][0] + 2 * dp[i - 1][1]) % MOD;
			dp[i][2] = dp[i - 1][1];
		}
	}
	int T{};
	cin >> T;
	while (T--) {
		int N{}, R{}, C{};
		cin >> N >> R >> C;
		ll ans{};
		if (C == 1 || C == N) {
			ans = R == 1 || R == 3 ? dp[N][1] : 0;
		} else {
			if (R == 1 || R == 3) {
				ans += dp[C - 1][0] * dp[N - C][0];
				ans += dp[C - 1][2] * dp[N - C][0];
				ans += dp[C - 1][0] * dp[N - C][2];
				ans %= MOD;
			} else {
				ans = 2 * dp[C][2] * dp[N - C + 1][2] % MOD;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
