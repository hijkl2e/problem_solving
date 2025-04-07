#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, L{}, K{};
	cin >> N >> L >> K;
	vector<vector<ll>> dp(N + 1, vector<ll>(N + 1));
	for (int i = 0; i <= N; ++i) {
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}
	for (int i = 0; i <= N; ++i) {
		partial_sum(dp[i].begin(), dp[i].end(), dp[i].begin());
	}
	string ans(N, '0');
	for (int i = 0; i < N; ++i) {
		if (K > dp[N - i - 1][L]) {
			K -= dp[N - i - 1][L--];
			ans[i] = '1';
		}
	}
	cout << ans << "\n";
	return 0;
}
