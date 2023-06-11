#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int dp[31][31][512];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	dp[0][0][0] = 1;
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 1; j <= K && i + j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				for (int l = 0; l < (1 << (K + 1)); ++l) {
					int &val = dp[i][k + 1][l ^ ((1 << j) | 1)];
					val = (val + dp[i][k][l]) % MOD;
				}
			}
		}
		for (int j = 0; j <= M; ++j) {
			for (int k = 0; k < (1 << K); ++k) {
				dp[i + 1][j][k] = dp[i][j][2 * k];
			}
		}
	}
	cout << dp[N - 1][M][0] << "\n";
	return 0;
}
