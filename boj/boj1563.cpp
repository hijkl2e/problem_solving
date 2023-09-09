#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e6;

int dp[1001][2][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	dp[0][0][0] = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 3; ++k) {
				dp[i + 1][j][0] = (dp[i + 1][j][0] + dp[i][j][k]) % MOD;
				if (j == 0) {
					dp[i + 1][1][0] = (dp[i + 1][1][0] + dp[i][j][k]) % MOD;
				}
				if (k < 2) {
					dp[i + 1][j][k + 1] = (dp[i + 1][j][k + 1] + dp[i][j][k]) % MOD;
				}
			}
		}
	}
	int ans{};
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			ans = (ans + dp[N][i][j]) % MOD;
		}
	}
	cout << ans << "\n";
	return 0;
}
