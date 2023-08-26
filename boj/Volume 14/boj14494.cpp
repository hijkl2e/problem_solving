#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<ll>> dp(N + 1, vector<ll>(M + 1));
	dp[0][0] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
		}
	}
	cout << dp[N][M] << "\n";
	return 0;
}
