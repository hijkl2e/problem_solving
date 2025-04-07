#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<ll> dp(100001);
	dp[0] = dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < dp.size(); ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
	}
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		ll ans{};
		for (int i = N % 2; i < 4 && i <= N; i += 2) {
			ans = (ans + dp[(N - i) / 2]) % MOD;
		}
		cout << ans << "\n";
	}
	return 0;
}
