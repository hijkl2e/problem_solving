#include <bits/stdc++.h>

using namespace std;

const int MOD = 1001113;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> dp(101, vector<int>(101));
	dp[1][0] = 1;
	for (int i = 1; i < 100; ++i) {
		for (int j = 0; j < i; ++j) {
			dp[i + 1][j] = (dp[i + 1][j] + (j + 1) * dp[i][j]) % MOD;
			dp[i + 1][j + 1] = (dp[i + 1][j + 1] + (i - j) * dp[i][j]) % MOD;
		}
	}
	int T{};
	cin >> T;
	while (T--) {
		int K{}, N{}, M{};
		cin >> K >> N >> M;
		cout << K << " " << dp[N][M] << "\n";
	}
	return 0;
}
