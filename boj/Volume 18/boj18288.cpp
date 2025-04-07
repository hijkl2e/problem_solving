#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int dp[2][11][2][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	dp[1][0][0][0] = 1;
	for (int i = 0; i < N; ++i) {
		memcpy(dp[0], dp[1], sizeof dp[1]);
		memset(dp[1], 0, sizeof dp[1]);
		for (int j = 0; j == 0 || j < K; ++j) {
			for (int k = 0; k < 2; ++k) {
				for (int l = 0; l < 2; ++l) {
					if (K) {
						int &val = dp[1][(j + 1) % K][0][l];
						val = (val + dp[0][j][k][l]) % MOD;
					}
					if (k == 0) {
						int &val = dp[1][j][1][l];
						val = (val + dp[0][j][0][l]) % MOD;
					}
					int &val = dp[1][j][0][1];
					val = (val + dp[0][j][k][l]) % MOD;
				}
			}
		}
	}
	int ans = (dp[1][0][0][1] + dp[1][0][1][1]) % MOD;
	cout << ans << "\n";
	return 0;
}
