#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	int M{};
	cin >> M;
	partial_sum(A.begin(), A.end(), A.begin());
	vector<vector<int>> dp(3, vector<int>(N + 1));
	for (int i = 1; i + M - 1 <= N; ++i) {
		dp[0][i] = A[i + M - 1] - A[i - 1];
	}
	for (int k = 1; k < 3; ++k) {
		int maxv{};
		for (int j = N - M + 1; j > 0; --j) {
			dp[k][j] = A[j + M - 1] - A[j - 1] + maxv;
			maxv = max(maxv, dp[k - 1][j + M - 1]);
		}
	}
	int ans = *max_element(dp[2].begin(), dp[2].end());
	cout << ans << "\n";
	return 0;
}
