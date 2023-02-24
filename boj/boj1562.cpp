#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9;

ll dp[101][1024][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	for (int i = 1; i < 10; ++i) {
		dp[1][1 << i][i] = 1;
	}
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < 1024; ++j) {
			for (int k = 0; k < 10; ++k) {
				if (k) {
					ll &val = dp[i + 1][j | (1 << (k - 1))][k - 1];
					val = (val + dp[i][j][k]) % MOD;
				}
				if (k < 9) {
					ll &val = dp[i + 1][j | (1 << (k + 1))][k + 1];
					val = (val + dp[i][j][k]) % MOD;
				}
			}
		}
	}
	ll ans{};
	for (int i = 0; i < 10; ++i) {
		ans = (ans + dp[N][1023][i]) % MOD;
	}
	cout << ans << "\n";
	return 0;
}
