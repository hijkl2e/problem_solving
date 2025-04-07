#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	deque<bool> A(N + 1, true);
	while (M--) {
		int x{};
		cin >> x;
		A[x] = false;
	}
	vector<vector<int>> dp(N + 1, vector<int>(151, INF));
	dp[1][0] = 0;
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < dp[i].size(); ++j) {
			if (dp[i][j] == INF) {
				continue;
			}
			for (int k = -1; k < 2; ++k) {
				if (j + k > 0 && i + j + k <= N && A[i + j + k]) {
					int &val= dp[i + j + k][j + k];
					val = min(val, dp[i][j] + 1);
				}
			}
		}
	}
	int ans = *min_element(dp[N].begin(), dp[N].end());
	if (ans == INF) {
		ans = -1;
	}
	cout << ans << "\n";
	return 0;
}
