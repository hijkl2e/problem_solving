#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<ll> dp(10000001);
	dp[0] = dp[1] = 1, dp[4] = 2;
	for (int i = 5; i < dp.size(); ++i) {
		dp[i] = (i + 1) * dp[i - 1] - (i - 2) * dp[i - 2] - (i - 5) * dp[i - 3] + (i - 3) * dp[i - 4];
		dp[i] = (dp[i] % MOD + MOD) % MOD;
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
