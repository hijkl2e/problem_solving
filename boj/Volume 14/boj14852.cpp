#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> dp(N + 1);
	dp[0] = 1, dp[1] = 2;
	ll X = 3;
	for (int i = 2; i <= N; ++i) {
		dp[i] = (dp[i - 2] + 2 * X) % MOD;
		X = (X + dp[i]) % MOD;
	}
	cout << dp[N] << "\n";
	return 0;
}
