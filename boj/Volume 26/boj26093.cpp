#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<vector<int>> dp(N, vector<int>(K + 2));
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j <= K; ++j) {
			cin >> dp[i][j];
		}
	}
	for (int i = 1; i < N; ++i) {
		int idx = max_element(dp[i - 1].begin(), dp[i - 1].end()) - dp[i - 1].begin();
		int x = dp[i - 1][idx];
		int y = max(*max_element(dp[i - 1].begin(), dp[i - 1].begin() + idx),
					*max_element(dp[i - 1].begin() + idx + 1, dp[i - 1].end()));
		for (int j = 1; j <= K; ++j) {
			dp[i][j] += dp[i - 1][j] == x ? y : x;
		}
	}
	int ans{};
	for (int i = 1; i <= K; ++i) {
		ans = max(ans, dp[N - 1][i]);
	}
	cout << ans << "\n";
	return 0;
}
