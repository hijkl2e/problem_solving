#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int A[33][33];
ll dp[33][33][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> A[i][j];
		}
	}
	dp[1][2][0] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (A[i][j]) {
				continue;
			}
			dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];
			dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][2];
			if (A[i - 1][j] == 0 && A[i][j - 1] == 0) {
				for (int k = 0; k < 3; ++k) {
					dp[i][j][2] += dp[i - 1][j - 1][k];
				}
			}
		}
	}
	ll ans{};
	for (int i = 0; i < 3; ++i) {
		ans += dp[N][N][i];
	}
	cout << ans << "\n";
	return 0;
}
