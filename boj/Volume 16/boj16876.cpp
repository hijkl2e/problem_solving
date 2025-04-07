#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<deque<bool>> dp(M + 1, deque<bool>(10001));
	if (M % 2) {
		fill(dp[0].begin(), dp[0].begin() + N + 1, true);
	} else {
		fill(dp[0].begin() + N + 1, dp[0].end(), true);
	}
	vector<int> A{1, 10, 100, 1000, 10000};
	for (int i = 1; i <= M; ++i) {
		for (int j = 0; j < dp[i].size(); ++j) {
			for (int k = 0; k < 4; ++k) {
				int r = j % A[k + 1];
				int x = j - r + (r + A[k]) % A[k + 1];
				if (!dp[i - 1][x]) {
					dp[i][j] = true;
					break;
				}
			}
		}
	}
	cout << (dp[M][N] ? "koosaga" : "cubelover") << "\n";
	return 0;
}
