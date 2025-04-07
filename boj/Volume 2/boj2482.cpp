#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 3;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<vector<ll>> dp(N + 1, vector<ll>(K + 1));
	dp[0][0] = dp[1][0] = dp[1][1] = 1;
	for (int i = 2; i <= N; ++i) {
		dp[i][0] = 1;
		for (int j = 1; j <= K; ++j) {
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
	ll ans = (dp[N - 3][K - 1] + dp[N - 1][K]) % MOD;
	cout << ans << "\n";
	return 0;
}
