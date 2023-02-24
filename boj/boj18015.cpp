#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9;

ll dp[2001][2001][2][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, B{};
	cin >> N >> B;
	for (int i = 1; i < B; ++i) {
		dp[1][i][0][i == B - 1] = 1;
	}
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < B; ++j) {
			for (int k = 0; k < 2; ++k) {
				for (int l = 0; l < 2; ++l) {
					if (j) {
						ll &val = dp[i + 1][j - 1][k || (j == 1)][l];
						val = (val + dp[i][j][k][l]) % MOD;
					}
					if (j < B - 1) {
						ll &val = dp[i + 1][j + 1][k][l || (j == B - 2)];
						val = (val + dp[i][j][k][l]) % MOD;
					}
				}
			}
		}
	}
	ll ans{};
	for (int i = 0; i < B; ++i) {
		ans = (ans + dp[N][i][1][1]) % MOD;
	}
	cout << ans << "\n";
	return 0;
}
