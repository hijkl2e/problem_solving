#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	vector<vector<int>> dp(N + 1, vector<int>(N + 1, -INF));
	dp[0][0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
			if (A[i] > B[j]) {
				dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + B[j]);
			}
		}
	}
	int ans = *max_element(dp[N].begin(), dp[N].end());
	for (int i = 0; i < N; ++i) {
		ans = max(ans, dp[i][N]);
	}
	cout << ans << "\n";
	return 0;
}
