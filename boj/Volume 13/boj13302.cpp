#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	deque<bool> A(N + 1);
	while (M--) {
		int x{};
		cin >> x;
		A[x] = true;
	}
	vector<vector<int>> dp(N + 1, vector<int>(41, INF));
	dp[0][0] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < 41; ++j) {
			if (A[i]) {
				dp[i][j] = dp[i - 1][j];
				continue;
			}
			dp[i][j] = dp[i - 1][j] + 10000;
			if (j > 0) {
				dp[i][j] = min(dp[i][j], dp[max(i - 3, 0)][j - 1] + 25000);
			}
			if (j > 1) {
				dp[i][j] = min(dp[i][j], dp[max(i - 5, 0)][j - 2] + 37000);
			}
			if (j + 3 < 41) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j + 3]);
			}
		}
	}
	int ans = *min_element(dp[N].begin(), dp[N].end());
	cout << ans << "\n";
	return 0;
}
