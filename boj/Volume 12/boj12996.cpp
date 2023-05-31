#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> nCr(N + 1, vector<int>(N + 1));
	for (int i = 0; i <= N; ++i) {
		nCr[i][0] = nCr[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % MOD;
		}
	}
	vector<vector<int>> dp(4, vector<int>(N + 1));
	dp[0][N] = 1;
	for (int n = 0; n < 3; ++n) {
		int x{};
		cin >> x;
		for (int i = 0; i <= N; ++i) {
			for (int j = 0; j <= i && j <= x; ++j) {
				int k = x - j;
				if (N - i < k) {
					continue;
				}
				int &val = dp[n + 1][i - j];
				val = (val + 1LL * nCr[i][j] * nCr[N - i][k] % MOD * dp[n][i]) % MOD;
			}
		}
	}
	cout << dp[3][0] << "\n";
	return 0;
}
