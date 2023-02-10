#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e4 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<vector<int>> dp(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; ++i) {
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
	cout << dp[N][K] << "\n";
	return 0;
}
