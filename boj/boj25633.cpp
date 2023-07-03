#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<vector<int>> dp(2, vector<int>(N + 1, -1));
	for (int i = 0; i < N; ++i) {
		copy(dp[1].begin(), dp[1].end(), dp[0].begin());
		dp[1][1] = max(dp[1][1], A[i]);
		for (int j = 1; j <= i; ++j) {
			if (dp[0][j] == -1 || dp[0][j] < A[i]) {
				continue;
			}
			dp[1][j + 1] = max(dp[1][j + 1], dp[0][j] + A[i]);
		}
	}
	int ans = find(dp[1].begin() + 1, dp[1].end(), -1) - dp[1].begin() - 1;
	cout << ans << "\n";
	return 0;
}
