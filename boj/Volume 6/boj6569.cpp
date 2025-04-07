#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	while (cin >> N >> M, N) {
		vector<vector<ll>> dp(N * M + 1, vector<ll>(1 << M));
		dp[0][0] = 1;
		for (int i = 0; i < N * M; ++i) {
			for (int j = 0; j < (1 << M); ++j) {
				if (j & 1) {
					dp[i + 1][j >> 1] += dp[i][j];
					continue;
				}
				if (i % M < M - 1 && (j & 2) == 0) {
					dp[i + 1][(j >> 1) | 1] += dp[i][j];
				}
				dp[i + 1][(j >> 1) | (1 << (M - 1))] += dp[i][j];
			}
		}
		cout << dp.back()[0] << "\n";
	}
	return 0;
}
