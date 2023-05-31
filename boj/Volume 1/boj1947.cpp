#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> dp(N + 1);
	dp[0] = 1;
	for (int i = 2; i <= N; ++i) {
		dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % MOD;
	}
	cout << dp[N] << "\n";
	return 0;
}
