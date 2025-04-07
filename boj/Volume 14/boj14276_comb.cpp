#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int nCr[222][222];
int dp[31][31][256];

int nHr(int n, int r) {
	return nCr[n + r - 1][r];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	if (N == 1) {
		cout << (M ? 0 : 1) << "\n";
		return 0;
	}
	K = min(K, N - 1);
	for (int i = 0; i < 222; ++i) {
		nCr[i][0] = nCr[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % MOD;
		}
	}
	dp[0][0][0] = 1;
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j <= M; ++j) {
			for (int k = 0; k < (1 << K); ++k) {
				if (dp[i][j][k] == 0) {
					continue;
				}
				for (int l = (1 << min(K, N - i - 1)) - 1; l >= 0; --l) {
					int cnt = __builtin_popcount(l ^ (k >> 1));
					if ((cnt + k) % 2 == 0 && j + cnt <= M) {
						int &val = dp[i + 1][j + cnt][l];
						val = (val + dp[i][j][k]) % MOD;
					}
				}
			}
		}
	}
	int ans{};
	int x = K * N - K * (K + 1) / 2;
	for (int i = M % 2; i <= M; i += 2) {
		ans = (ans + 1LL * nHr(x, (M - i) / 2) * dp[N - 1][i][0]) % MOD;
	}
	cout << ans << "\n";
	return 0;
}
