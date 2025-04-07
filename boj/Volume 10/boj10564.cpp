#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		vector<int> A(M);
		for (int i = 0; i < M; ++i) {
			cin >> A[i];
		}
		vector<vector<int>> dp(2, vector<int>(N + 1, -1));
		dp[1][0] = 0;
		int ans = -1;
		for (int i = 1; i < 100; ++i) {
			copy(dp[1].begin(), dp[1].end(), dp[0].begin());
			fill(dp[1].begin(), dp[1].end(), -1);
			for (int j = 0; j < M; ++j) {
				for (int k = 0; k + i * A[j] <= N; ++k) {
					if (dp[0][k] == -1) {
						continue;
					}
					int &val = dp[1][k + i * A[j]];
					val = max(val, dp[0][k] + A[j]);
				}
			}
			ans = max(ans, dp[1][N]);
		}
		cout << ans << "\n";
	}
	return 0;
}
