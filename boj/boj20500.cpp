#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<ll>> dp(N + 1, vector<ll>(15));
	dp[0][0] = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 15; ++j) {
			for (int k = 1; k < 6; k += 4) {
				ll &val = dp[i + 1][(10 * j + k) % 15];
				val = (val + dp[i][j]) % MOD;
			}
		}
	}
	cout << dp[N][0] << "\n";
	return 0;
}
