#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<vector<int>> A(2, vector<int>(N + 1));
		for (int i = 0; i < 2; ++i) {
			for (int j = 1; j <= N; ++j) {
				cin >> A[i][j];
			}
		}
		vector<vector<int>> dp(2, vector<int>(N + 1));
		dp[0][1] = A[0][1];
		dp[1][1] = A[1][1];
		for (int i = 2; i <= N; ++i) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + A[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + A[1][i];
		}
		int ans = max(dp[0][N], dp[1][N]);
		cout << ans << "\n";
	}
	return 0;
}
