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
	vector<vector<int>> dp(N + 1, vector<int>(2));
	for (int i = 1; i <= N; ++i) {
		dp[i][0] = max(dp[i - 1][0], 0) + A[i];
		dp[i][1] = (i == 1 ? 0 : max(dp[i - 2][0], dp[i - 1][1])) + A[i];
	}
	int ans = -1e9;
	for (int i = 1; i <= N; ++i) {
		ans = max({ans, dp[i][0], dp[i][1]});
	}
	cout << ans << "\n";
	return 0;
}
