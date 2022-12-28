#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<ll>> dp(100001, vector<ll>(4));
	dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
	for (int i = 4; i < dp.size(); ++i) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
	}
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		ll ans = (dp[N][1] + dp[N][2] + dp[N][3]) % MOD;
		cout << ans << "\n";
	}
	return 0;
}
