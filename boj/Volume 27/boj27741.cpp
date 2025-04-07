#include <bits/stdc++.h>

using namespace std;

const int dx[2]{1, 0};
const int dy[2]{0, 1};

int N;
int A[301][301];
int dp[301][301][301];

int solve(int x, int y, int k) {
	if (dp[x][y][k] != -1) {
		return dp[x][y][k];
	}
	dp[x][y][k] = 0;
	for (int i = 0; i < 2; ++i) {
		int nx = x, ny = y;
		for (int j = 0; j < k; ++j) {
			nx += dx[i];
			ny += dy[i];
			if (nx == N || ny == N || A[nx][ny]) {
				break;
			}
			if (solve(nx, ny, k) == 0) {
				return dp[x][y][k] = 1;
			}
		}
	}
	for (int i = 1; i < k; ++i) {
		if (k % i == 0 && solve(x, y, i) == 0) {
			return dp[x][y][k] = 1;
		}
	}
	return dp[x][y][k];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{};
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	memset(dp, -1, sizeof dp);
	cout << solve(0, 0, K) << "\n";
	return 0;
}
