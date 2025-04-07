#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<vector<ll>> dp(K + 1, vector<ll>(N + 1));
	dp[0][0] = 1;
	for (int i = 1; i <= K; ++i) {
		dp[i][0] = 1;
		for (int j = 1; j <= N; ++j) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
	cout << dp[K][N] << "\n";
	return 0;
}
