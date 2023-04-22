#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<int>> dp(N, vector<int>(M));
	dp[0][0] = A[0][0];
	for (int i = 1; i < M; ++i) {
		dp[0][i] = dp[0][i - 1] + A[0][i];
	}
	for (int i = 1; i < N; ++i) {
		dp[i][0] = dp[i - 1][0] + A[i][0];
		for (int j = 1; j < M; ++j) {
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + A[i][j];
		}
		int x = dp[i - 1][M - 1] + A[i][M - 1];
		dp[i][M - 1] = max(dp[i][M - 1], x);
		for (int j = M - 2; j >= 0; --j) {
			x = max(x, dp[i - 1][j]) + A[i][j];
			dp[i][j] = max(dp[i][j], x);
		}
	}
	cout << dp[N - 1][M - 1] << "\n";
	return 0;
}
