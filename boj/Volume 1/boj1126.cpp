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
	vector<vector<int>> dp(2, vector<int>(250001, -1));
	dp[1][0] = 0;
	for (int i = 0; i < N; ++i) {
		copy(dp[1].begin(), dp[1].end(), dp[0].begin());
		for (int j = 0; j < dp[0].size(); ++j) {
			if (dp[0][j] == -1) {
				continue;
			}
			int x = j + A[i];
			if (x < dp[0].size()) {
				dp[1][x] = max(dp[1][x], dp[0][j]);
			}
			x = abs(j - A[i]);
			if (x < dp[0].size()) {
				dp[1][x] = max(dp[1][x], dp[0][j] + min(j, A[i]));
			}
		}
	}
	cout << (dp[1][0] ? dp[1][0] : -1) << "\n";
	return 0;
}
