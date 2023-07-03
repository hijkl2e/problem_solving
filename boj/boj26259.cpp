#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	int x1{}, y1{}, x2{}, y2{};
	cin >> x1 >> y1 >> x2 >> y2;
	if (x1 > x2) {
		swap(x1, x2);
	}
	if (y1 > y2) {
		swap(y1, y2);
	}
	vector<vector<int>> B(N, vector<int>(M, 3));
	if (x1 == x2 && x1) {
		for (int i = y1; i < y2; ++i) {
			B[x1 - 1][i] = 1;
		}
	} else if (y1 == y2 && y1) {
		for (int i = x1; i < x2; ++i) {
			B[i][y1 - 1] = 2;
		}
	}
	vector<vector<int>> dp(N, vector<int>(M, -INF));
	dp[0][0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (dp[i][j] == -INF) {
				continue;
			}
			dp[i][j] += A[i][j];
			if (i + 1 < N && (B[i][j] & 2)) {
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			}
			if (j + 1 < M && (B[i][j] & 1)) {
				dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
			}
		}
	}
	if (dp[N - 1][M - 1] == -INF) {
		cout << "Entity\n";
	} else {
		cout << dp[N - 1][M - 1] << "\n";
	}
	return 0;
}
