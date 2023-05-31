#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int n = S.size();
	vector<vector<int>> dp(n + 1, vector<int>(n));
	for (int i = n - 1; i >= 0; --i) {
		dp[i + 1][i] = 1, dp[i][i] = 2;
		for (int j = i + 1; j < n; ++j) {
			dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - (S[i] == S[j] ? 0 : dp[i + 1][j - 1])) % MOD;
		}
	}
	int ans = (dp[0][n - 1] + MOD - 1) % MOD;
	cout << ans << "\n";
	return 0;
}
