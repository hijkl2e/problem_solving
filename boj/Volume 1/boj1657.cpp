#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> A{
		{10, 8, 7, 5, -1, 1}, {8, 6, 4, 3, -1, 1}, {7, 4, 3, 2, -1, 1},
		{5, 3, 2, 2, -1, 1}, {-1, -1, -1, -1, -1, -1}, {1, 1, 1, 1, -1, 0}
	};
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> B(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, B[i]);
	}
	vector<vector<int>> dp(N * M + 1, vector<int>(1 << M));
	dp[0][0] = 0;
	for (int i = 0; i < N * M; ++i) {
		for (int j = 0; j < (1 << M); ++j) {
			if (j & 1) {
				int &val = dp[i + 1][j >> 1];
				val = max(val, dp[i][j]);
				continue;
			}
			int x = i / M, y = i % M;
			if (y < M - 1 && (j & 2) == 0) {
				int &val = dp[i + 1][(j >> 1) | 1];
				val = max(val, dp[i][j] + A[B[x][y] - 'A'][B[x][y + 1] - 'A']);
			}
			if (x < N - 1) {
				int &val = dp[i + 1][(j >> 1) | (1 << (M - 1))];
				val = max(val, dp[i][j] + A[B[x][y] - 'A'][B[x + 1][y] - 'A']);
			}
			int &val = dp[i + 1][j >> 1];
			val = max(val, dp[i][j]);
		}
	}
	cout << dp.back()[0] << "\n";
	return 0;
}
