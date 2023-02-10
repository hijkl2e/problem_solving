#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<ll>> dp(2 * N + 1, vector<ll>(N + 1));
	for (int i = 1; i < dp.size(); ++i) {
		dp[i][0] = 1;
		if (i <= N) {
			dp[i][i] = 1;
		}
		for (int j = 1; j < i && j <= N; ++j) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
		}
	}
	cout << dp[2 * N][N] << " " << N * N << "\n";
	return 0;
}
