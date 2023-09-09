#include <bits/stdc++.h>

using namespace std;

int dp[101][101][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	dp[0][0][0] = 1;
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j <= i; ++j) {
			dp[i + 1][j][0] += dp[i][j][0] + dp[i][j][1];
			dp[i + 1][j][1] += dp[i][j][0];
			dp[i + 1][j + 1][1] += dp[i][j][1];
		}
	}
	int T{};
	cin >> T;
	while (T--) {
		int N{}, K{};
		cin >> N >> K;
		int ans = dp[N][K][0] + dp[N][K][1];
		cout << ans << "\n";
	}
	return 0;
}
