#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e5;

int dp[101][101][4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int w{}, h{};
	cin >> w >> h;
	dp[1][1][0] = dp[1][1][1] = 1;
	for (int i = 1; i <= w; ++i) {
		for (int j = i == 1 ? 2 : 1; j <= h; ++j) {
			dp[i][j][0] = dp[i - 1][j][3];
			dp[i][j][1] = dp[i][j - 1][2];
			dp[i][j][2] = (dp[i - 1][j][0] + dp[i - 1][j][2]) % MOD;
			dp[i][j][3] = (dp[i][j - 1][1] + dp[i][j - 1][3]) % MOD;
		}
	}
	int ans{};
	for (int i = 0; i < 4; ++i) {
		ans += dp[w][h][i];
	}
	ans %= MOD;
	cout << ans << "\n";
	return 0;
}
