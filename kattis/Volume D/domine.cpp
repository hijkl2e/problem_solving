#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<vector<int>> A(N, vector<int>(3));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<ll>> dp(K + 1, vector<ll>(8, -INF));
	dp[0][0] = 0;
	dp[1][3] = A[0][0] + A[0][1];
	dp[1][6] = A[0][1] + A[0][2];
	for (int i = 1; i < N; ++i) {
		for (int j = K; j >= 0; --j) {
			for (int k = 7; k >= 0; --k) {
				int x = __builtin_popcount(k);
				if (j + x > K) {
					continue;
				}
				ll y = -INF;
				for (int l = 0; l < 8; ++l) {
					if ((k & l) == 0) {
						y = max(y, dp[j][l]);
					}
				}
				for (int l = 0; l < 3; ++l) {
					if (k & (1 << l)) {
						y += A[i - 1][l] + A[i][l];
					}
				}
				dp[j + x][k] = max(dp[j + x][k], y);
				if (j + x == K) {
					continue;
				}
				if ((k & 3) == 0) {
					ll &z = dp[j + x + 1][k | 3];
					z = max(z, y + A[i][0] + A[i][1]);
				}
				if ((k & 6) == 0) {
					ll &z = dp[j + x + 1][k | 6];
					z = max(z, y + A[i][1] + A[i][2]);
				}
			}
			fill(dp[j].begin() + 1, dp[j].end(), -INF);
		}
	}
	ll ans = *max_element(dp[K].begin(), dp[K].end());
	cout << ans << "\n";
	return 0;
}
