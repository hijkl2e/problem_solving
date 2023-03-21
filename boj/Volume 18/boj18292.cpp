#include <bits/stdc++.h>

using namespace std;

const int INF = 0xbfbfbfbf;

int dp[11][1024][61];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	vector<int> B;
	for (int i = 0; i < (1 << M); ++i) {
		bool flag = true;
		for (int j = 0; j < M; ++j) {
			if (((i >> j) & 3) == 3) {
				flag = false;
				break;
			}
		}
		if (flag) {
			B.push_back(i);
		}
	}
	memset(dp, 0xbf, sizeof dp);
	dp[0][0][0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int x : B) {
			int sum{};
			for (int j = 0; j < M; ++j) {
				if (x & (1 << j)) {
					sum += A[i][j];
				}
			}
			for (int y : B) {
				for (int j = 0; j <= K; ++j) {
					if (dp[i][y][j] == INF) {
						continue;
					}
					if ((x & y) == 0) {
						int &val = dp[i + 1][x][j + __builtin_popcount(x)];
						val = max(val, dp[i][y][j] + sum);
					}
				}
			}
		}
	}
	int ans = INF;
	for (int x : B) {
		ans = max(ans, dp[N][x][K]);
	}
	cout << ans << "\n";
	return 0;
}
