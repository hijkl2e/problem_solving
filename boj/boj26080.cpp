#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int D{};
	ll K{};
	cin >> D >> K;
	int x = D / 2 - 1;
	int y = min(x, 35);
	vector<vector<ll>> dp(x + y + 1, vector<ll>(y + 1));
	dp[0][0] = 1;
	for (int i = 1; i <= x + y; ++i) {
		for (int j = 0; j <= y && j <= i / 2; ++j) {
			dp[i][j] = dp[i - 1][j];
			if (j) {
				dp[i][j] += dp[i - 1][j - 1];
			}
			dp[i][j] = min(dp[i][j], INF);
		}
	}
	if (K > dp[x + y][y]) {
		cout << "-1\n";
		return 0;
	}
	string ans(x - y + 1, 'A');
	for (int i = x + y - 1, j = y - 1; j >= 0; --i) {
		if (K <= dp[i][j]) {
			ans += "A";
			--j;
		} else {
			ans += "D";
			K -= dp[i][j];
		}
	}
	ans += string(D - ans.size(), 'D');
	cout << ans << "\n";
	return 0;
}
