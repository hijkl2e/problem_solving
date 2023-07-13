#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll dp[2][105][105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ll> C(++N + 1);
	C[0] = C[1] = 1;
	for (int i = 2; i <= N; ++i) {
		for (int j = 0; i - j - 1 >= 0; ++j) {
			C[i] = (C[i] + C[j] * C[i - j - 1]) % M;
		}
	}
	for (int i = 1; i <= N; ++i) {
		dp[0][i][1] = C[i - 1];
		dp[1][i][2] = (i - 1) * C[i - 1] % M;
	}
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j <= i; ++j) {
			for (int k = 1; i + k <= N; ++k) {
				for (int l = 0; l < 2; ++l) {
					for (int m = l; m < 2 && (m == 0 || j > 1); ++m) {
						ll &val = dp[m][i + k][j + 1];
						val = (val + dp[l][i][j] * C[k - (l == m)]) % M;
					}
				}
			}
		}
	}
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j <= i; ++j) {
			for (int k = 1; k <= j + 1; ++k) {
				dp[1][i + 1][k] = (dp[1][i + 1][k] + dp[1][i][j]) % M;
			}
		}
	}
	for (int i = 1; i < N; ++i) {
		cout << dp[1][i + 1][1] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
