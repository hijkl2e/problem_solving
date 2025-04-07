#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<ll> dp(68);
	dp[0] = 1, dp[1] = 1, dp[2] = 2, dp[3] = 4;
	for (int i = 4; i < dp.size(); ++i) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
	}
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cout << dp[N] << "\n";
	}
	return 0;
}
