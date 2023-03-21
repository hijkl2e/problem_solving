#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> dp(N + 1, vector<int>(10));
	fill(dp[1].begin(), dp[1].end(), 1);
	for (int i = 2; i <= N; ++i) {
		dp[i][0] = dp[i - 1][0];
		for (int j = 1; j < 10; ++j) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
	int ans = accumulate(dp[N].begin(), dp[N].end(), 0) % MOD;
	cout << ans << "\n";
	return 0;
}
