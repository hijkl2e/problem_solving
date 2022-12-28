#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<ll>> dp(100001, vector<ll>(2));
	dp[0][0] = dp[1][1] = dp[2][0] = dp[2][1] = 1;
	for (int i = 3; i < dp.size(); ++i) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 2][1] + dp[i - 3][1]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 2][0] + dp[i - 3][0]) % MOD;
	}
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cout << dp[N][1] << " " << dp[N][0] << "\n";
	}
	return 0;
}
