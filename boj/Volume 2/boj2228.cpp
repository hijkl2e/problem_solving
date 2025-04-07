#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	partial_sum(A.begin(), A.end(), A.begin());
	vector<vector<int>> dp(M, vector<int>(N + 1, -INF));
	int minv{};
	for (int i = 1; i <= N; ++i) {
		dp[0][i] = max(dp[0][i - 1], A[i] - minv);
		minv = min(minv, A[i]);
	}
	for (int i = 1; i < M; ++i) {
		for (int j = 1; j <= N; ++j) {
			dp[i][j] = dp[i][j - 1];
			for (int k = j - 1; k > 0; --k) {
				dp[i][j] = max(dp[i][j], dp[i - 1][k - 1] + A[j] - A[k]);
			}
		}
	}
	cout << dp[M - 1][N] << "\n";
	return 0;
}
