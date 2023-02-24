#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= i; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<int>> dp(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + A[i][j];
		}
	}
	int ans = *max_element(dp[N].begin(), dp[N].end());
	cout << ans << "\n";
	return 0;
}
