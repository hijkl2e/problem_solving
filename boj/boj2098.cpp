#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
			if (A[i][j] == 0) {
				A[i][j] = INF;
			}
		}
	}
	vector<vector<int>> dp(N - 1, vector<int>(1 << (N - 1), INF));
	for (int i = 0; i < (1 << (N - 1)); ++i) {
		for (int j = 0; j < N - 1; ++j) {
			if ((i & (1 << j)) == 0) {
				continue;
			} else if (i == (1 << j)) {
				dp[j][i] = A[N - 1][j];
				continue;
			}
			for (int k = 0; k < N - 1; ++k) {
				if (i & (1 << k)) {
					dp[j][i] = min(dp[j][i], dp[k][i & ~(1 << j)] + A[k][j]);
				}
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < N - 1; ++i) {
		ans = min(ans, dp[i].back() + A[i][N - 1]);
	}
	cout << ans << "\n";
	return 0;
}
