#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, P{};
	cin >> N >> P;
	vector<ll> F(N + 1);
	F[0] = 1, F[1] = 2;
	for (int i = 2; i <= N; ++i) {
		F[i] = (F[i - 2] + F[i - 1]) % P;
	}
	vector<vector<ll>> dp(N + 1, vector<ll>(N + 1));
	dp[0][0] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int j = i; j <= N && j <= i * (i + 1) / 2; ++j) {
			for (int k = 1; k <= i; ++k) {
				for (int l = 2 * k - 1; l <= j && l <= k * (k + 1) / 2; ++l) {
					dp[i][j] += dp[i - k][j - l] * F[k] % P * dp[k - 1][l - k] % P;
				}
			}
			dp[i][j] %= P;
		}
	}
	ll ans{};
	for (int i = 1; i <= N; ++i) {
		ans += dp[i][N];
	}
	ans %= P;
	cout << ans << "\n";
	return 0;
}
