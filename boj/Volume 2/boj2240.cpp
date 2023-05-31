#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<vector<int>> dp(M + 1, vector<int>(N + 1, -INF));
	dp[0][0] = 0;
	for (int i = 0; i <= M; ++i) {
		for (int j = 0; j < N; ++j) {
			dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + (A[j] == i % 2 + 1));
			if (i < M) {
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			}
		}
	}
	int ans{};
	for (int i = 0; i <= M; ++i) {
		ans = max(ans, dp[i][N]);
	}
	cout << ans << "\n";
	return 0;
}
