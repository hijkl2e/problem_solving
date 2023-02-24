#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<ll>> dp(N + 1, vector<ll>(10));
	fill(dp[1].begin() + 1, dp[1].end(), 1);
	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j < 10; ++j) {
			dp[i][j] = ((j ? dp[i - 1][j - 1] : 0) + (j < 9 ? dp[i - 1][j + 1] : 0)) % MOD;
		}
	}
	ll ans = accumulate(dp[N].begin(), dp[N].end(), 0LL) % MOD;
	cout << ans << "\n";
	return 0;
}
