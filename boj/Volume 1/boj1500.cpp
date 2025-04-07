#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int S{}, K{};
	cin >> S >> K;
	vector<vector<ll>> dp(K + 1, vector<ll>(S + 1));
	dp[0][0] = 1;
	for (int i = 1; i <= K; ++i) {
		for (int j = i; j <= S; ++j) {
			for (int k = 1; k <= j; ++k) {
				dp[i][j] = max(dp[i][j], k * dp[i - 1][j - k]);
			}
		}
	}
	cout << dp[K][S] << "\n";
	return 0;
}
