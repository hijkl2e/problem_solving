#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

ll dp[101][101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, L{}, R{};
	cin >> N >> L >> R;
	dp[1][1][1] = 1;
	for (int i = 2; i <= N; ++i) {
		for (int j = 1; j <= i; ++j) {
			for (int k = 1; k <= i; ++k) {
				dp[i][j][k] = (dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1]
							+ (i - 2) * dp[i - 1][j][k]) % MOD;
			}
		}
	}
	ll ans = dp[N][L][R] % MOD;
	cout << ans << "\n";
	return 0;
}
