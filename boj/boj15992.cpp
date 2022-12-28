#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<ll>> dp(1001, vector<ll>(1001));
	dp[0][0] = dp[1][1] = dp[2][1] = dp[2][2] = 1;
	for (int i = 3; i < dp.size(); ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 2][j - 1] + dp[i - 3][j - 1]) % MOD;
		}
	}
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		cout << dp[N][M] << "\n";
	}
	return 0;
}
