#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> dp(15, vector<int>(15));
	for (int i = 1; i < 15; ++i) {
		dp[0][i] = i;
	}
	for (int i = 1; i < 15; ++i) {
		for (int j = 1; j < 15; ++j) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	int T{};
	cin >> T;
	while (T--) {
		int K{}, N{};
		cin >> K >> N;
		cout << dp[K][N] << "\n";
	}
	return 0;
}
