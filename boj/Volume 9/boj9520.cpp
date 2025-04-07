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
		}
	}
	vector<vector<int>> dp(N, vector<int>(N, INF));
	dp[0][0] = 0, dp[1][0] = A[1][0];
	for (int i = 2; i < N; ++i) {
		for (int j = 0; j < i - 1; ++j) {
			dp[i][j] = dp[i - 1][j] + A[i - 1][i];
			dp[i][i - 1] = min(dp[i][i - 1], dp[i - 1][j] + A[j][i]);
		}
	}
	int ans = *min_element(dp[N - 1].begin(), dp[N - 1].end());
	cout << ans << "\n";
	return 0;
}
