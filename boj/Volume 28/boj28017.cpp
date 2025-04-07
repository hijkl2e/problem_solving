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
	copy(A[0].begin(), A[0].end(), dp[0].begin());
	for (int i = 1; i < N; ++i) {
		int p = min_element(dp[i - 1].begin(), dp[i - 1].end()) - dp[i - 1].begin();
		fill(dp[i].begin(), dp[i].end(), dp[i - 1][p]);
		dp[i - 1][p] = 1e9;
		dp[i][p] = *min_element(dp[i - 1].begin(), dp[i - 1].end());
		for (int j = 0; j < M; ++j) {
			dp[i][j] += A[i][j];
		}
	}
	int ans = *min_element(dp[N - 1].begin(), dp[N - 1].end());
	cout << ans << "\n";
	return 0;
}
