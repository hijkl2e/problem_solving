#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll K{};
	cin >> K;
	vector<vector<ll>> dp(87, vector<ll>(2));
	dp[1][0] = dp[1][1] = 1;
	for (int i = 2; i < dp.size(); ++i) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	int L = 1;
	while (K > dp[L][1]) {
		K -= dp[L++][1];
	}
	string ans(L, '0');
	ans[0] = '1';
	for (int i = 1; i < L; ++i) {
		if (K > dp[L - i][0]) {
			K -= dp[L - i][0];
			ans[i] = '1';
		}
	}
	cout << ans << "\n";
	return 0;
}
