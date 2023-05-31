#include <bits/stdc++.h>

using namespace std;

const int dx[8]{-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8]{-1, 0, 1, 1, 1, 0, -1, -1};

int dp[2][21][21][21][21];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, L{};
	cin >> N >> L;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	if (L % 2) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				dp[1][i][j][i][j] = 1;
			}
		}
	} else {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				for (int k = 0; k < 8; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (0 <= nx && nx < N && 0 <= ny && ny < N && A[i][j] == A[nx][ny]) {
						dp[1][i][j][nx][ny] = 1;
					}
				}
			}
		}
	}
	for (int n = (L - 1) / 2; n > 0; --n) {
		memcpy(dp[0], dp[1], sizeof dp[1]);
		memset(dp[1], 0, sizeof dp[1]);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				for (int k = 0; k < N; ++k) {
					for (int l = 0; l < N; ++l) {
						if (dp[0][i][j][k][l] == 0) {
							continue;
						}
						for (int m = 0; m < 8; ++m) {
							int nx1 = i + dx[m];
							int ny1 = j + dy[m];
							if (nx1 == -1 || nx1 == N || ny1 == -1 || ny1 == N) {
								continue;
							}
							for (int n = 0; n < 8; ++n) {
								int nx2 = k + dx[n];
								int ny2 = l + dy[n];
								if (nx2 == -1 || nx2 == N || ny2 == -1 || ny2 == N
										|| A[nx1][ny1] != A[nx2][ny2]) {
									continue;
								}
								dp[1][nx1][ny1][nx2][ny2] += dp[0][i][j][k][l];
							}
						}
					}
				}
			}
		}
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				for (int l = 0; l < N; ++l) {
					ans += dp[1][i][j][k][l];
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
