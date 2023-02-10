#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> dp(2 * N + 1, vector<int>(2 * N + 1));
	for (int i = 1; i < dp.size(); ++i) {
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}
	cout << dp[2 * N][N] << " " << N * N << "\n";
	return 0;
}
