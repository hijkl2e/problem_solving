#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000001;

int dp[101][101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	dp[0][0][0] = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= M; ++j) {
			for (int k = 0; k <= K; ++k) {
				if (dp[i][j][k] == 0) {
					continue;
				}
				dp[i + 1][j][k] = (dp[i + 1][j][k] + dp[i][j][k]) % MOD;
				if (j == M || k == K) {
					continue;
				}
				if (j + 2 <= M && k + 2 <= K) {
					int &val = dp[i + 1][j + 2][k + 2];
					val = (val + (M - j) * (M - j - 1) / 2LL * dp[i][j][k]) % MOD;
				}
				if (i + 2 <= N && k + 2 <= K) {
					int &val = dp[i + 2][j + 1][k + 2];
					val = (val + 1LL * (i + 1) * (M - j) * dp[i][j][k]) % MOD;
				}
				int &val = dp[i + 1][j + 1][k + 1];
				val = (val + (M - j) * dp[i][j][k]) % MOD;
			}
		}
	}
	int ans{};
	for (int i = 0; i <= M; ++i) {
		ans = (ans + dp[N][i][K]) % MOD;
	}
	cout << ans << "\n";
	return 0;
}
