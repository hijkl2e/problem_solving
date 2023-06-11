#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	if (N < 3) {
		cout << (M ? 0 : 1) << "\n";
		return 0;
	}
	vector<deque<bool>> dp(N + 1, deque<bool>(M + 1));
	dp[1][0] = dp[2][0] = true;
	for (int i = 2; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (!dp[i][j]) {
				continue;
			}
			for (int k = 1; i + k <= N && j + k * (k + 1) / 2 <= M; ++k) {
				dp[i + k][j + k * (k + 1) / 2] = true;
			}
		}
	}
	cout << dp[N][M] << "\n";
	return 0;
}
