#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll N, K;
vector<vector<ll>> dp(64, vector<ll>(64));

ll solve(ll x) {
	ll ret{};
	while (x) {
		ll y = x & -x;
		x -= y;
		int cnt = __builtin_popcountll((N & ~(y - 1)) ^ x);
		int n = __builtin_ctzll(y);
		if (0 <= K - cnt && K - cnt <= n) {
			ret += dp[n][K - cnt];
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll A{}, B{};
	cin >> N >> K >> A >> B;
	for (int i = 0; i < dp.size(); ++i) {
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}
	ll ans = solve(B + 1) - solve(A);
	cout << ans << "\n";
	return 0;
}
