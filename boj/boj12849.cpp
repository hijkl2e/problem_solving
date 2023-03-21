#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> G{
		{1, 2}, {0, 2, 3}, {0, 1, 3, 4}, {1, 2, 4, 5}, {2, 3, 5, 6}, {3, 4, 7}, {4, 7}, {5, 6}
	};
	int N{};
	cin >> N;
	vector<vector<int>> dp(2, vector<int>(8));
	dp[0][0] = 1;
	while (N--) {
		fill(dp[1].begin(), dp[1].end(), 0);
		for (int u = 0; u < 8; ++u) {
			for (int v : G[u]) {
				dp[1][v] = (dp[1][v] + dp[0][u]) % MOD;
			}
		}
		copy(dp[1].begin(), dp[1].end(), dp[0].begin());
	}
	cout << dp[0][0] << "\n";
	return 0;
}
