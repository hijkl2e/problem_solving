#include <bits/stdc++.h>

using namespace std;

const int MOD = 9901;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> dp(N * M + 1, vector<int>(1 << M));
	dp[0][0] = 1;
	for (int i = 0; i < N * M; ++i) {
		for (int j = 0; j < (1 << M); ++j) {
			if (j & 1) {
				int &val = dp[i + 1][j >> 1];
				val = (val + dp[i][j]) % MOD;
				continue;
			}
			if (i % M < M - 1 && (j & 2) == 0) {
				int &val = dp[i + 1][(j >> 1) | 1];
				val = (val + dp[i][j]) % MOD;
			}
			int &val = dp[i + 1][(j >> 1) | (1 << (M - 1))];
			val = (val + dp[i][j]) % MOD;
		}
	}
	cout << dp.back()[0] << "\n";
	return 0;
}
