#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{}, N{};
	while (cin >> K >> N) {
		vector<vector<double>> dp(N + 1, vector<double>(K + 1));
		fill(dp[1].begin(), dp[1].end(), 1);
		for (int i = 1; i < N; ++i) {
			copy(dp[i].begin(), dp[i].end(), dp[i + 1].begin());
			for (int j = 0; j <= K; ++j) {
				if (j + 1 <= K) {
					dp[i + 1][j + 1] += dp[i][j];
				}
				if (j) {
					dp[i + 1][j - 1] += dp[i][j];
				}
			}
		}
		double ans = accumulate(dp[N].begin(), dp[N].end(), 0.0) / pow(K + 1, N) * 100;
		cout << fixed << setprecision(5);
		cout << ans << "\n";
	}
	return 0;
}
