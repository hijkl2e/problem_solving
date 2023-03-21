#include <bits/stdc++.h>

using namespace std;

int dp[2][5][5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A;
	int x{};
	while (cin >> x, x) {
		A.push_back(x);
	}
	memset(dp, 0x3f, sizeof dp);
	dp[0][0][0] = 0;
	for (int x : A) {
		memset(dp[1], 0x3f, sizeof dp[1]);
		for (int i = 0; i < 5; ++i) {
			if (i == x) {
				continue;
			}
			for (int j = 0; j < 5; ++j) {
				dp[1][x][i] = min(dp[1][x][i], dp[0][j][i]
						+ (j == x ? 1 : j == 0 ? 2 : (j + 1) % 4 + 1 == x ? 4 : 3));
			}
		}
		for (int i = 0; i < 5; ++i) {
			if (i == x) {
				continue;
			}
			for (int j = 0; j < 5; ++j) {
				dp[1][i][x] = min(dp[1][i][x], dp[0][i][j]
						+ (j == x ? 1 : j == 0 ? 2 : (j + 1) % 4 + 1 == x ? 4 : 3));
			}
		}
		memcpy(dp[0], dp[1], sizeof dp[1]);
	}
	int ans = 1e9;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			ans = min(ans, dp[0][i][j]);
		}
	}
	cout << ans << "\n";
	return 0;
}
