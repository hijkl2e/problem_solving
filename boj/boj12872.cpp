#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, P{};
	cin >> N >> M >> P;
	vector<vector<ll>> dp(P + 1, vector<ll>(N + 2));
	dp[0][0] = 1;
	for (int i = 0; i < P; ++i) {
		for (int j = 0; j <= N; ++j) {
			dp[i + 1][j + 1] = (dp[i + 1][j + 1] + (N - j) * dp[i][j]) % MOD;
			dp[i + 1][j] = (dp[i + 1][j] + max(j - M, 0) * dp[i][j]) % MOD;
		}
	}
	cout << dp[P][N] << "\n";
	return 0;
}
