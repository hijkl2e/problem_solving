#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{}, w{};
	cin >> R >> C >> w;
	vector<vector<int>> dp(R + w - 1, vector<int>(R + w - 1));
	for (int i = 0; i < dp.size(); ++i) {
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	int ans{};
	for (int i = 0; i < w; ++i) {
		for (int j = 0; j <= i; ++j) {
			ans += dp[R + i - 1][C + j - 1];
		}
	}
	cout << ans << "\n";
	return 0;
}
