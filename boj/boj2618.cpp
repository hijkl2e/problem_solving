#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

vector<int> x, y;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	x.resize(M + 1);
	y.resize(M + 1);
	for (int i = 1; i <= M; ++i) {
		cin >> x[i] >> y[i];
	}
	vector<vector<int>> dp(M + 1, vector<int>(M + 1, INF));
	dp[1][0] = x[1] + y[1] - 2;
	dp[0][1] = 2 * N - x[1] - y[1];
	vector<vector<int>> par(M + 1, vector<int>(M + 1, -1));
	for (int i = 2; i <= M; ++i) {
		for (int j = 0; j < i - 1; ++j) {
			dp[i][j] = dp[i - 1][j] + abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
			dp[j][i] = dp[j][i - 1] + abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
			int val = dp[j][i - 1] + abs(x[i] - (j ? x[j] : 1)) + abs(y[i] - (j ? y[j] : 1));
			if (dp[i][i - 1] > val) {
				dp[i][i - 1] = val;
				par[i][i - 1] = j;
			}
			val = dp[i - 1][j] + abs(x[i] - (j ? x[j] : N)) + abs(y[i] - (j ? y[j] : N));
			if (dp[i - 1][i] > val) {
				dp[i - 1][i] = val;
				par[i - 1][i] = j;
			}
		}
	}
	int x{}, y{};
	x = y = M;
	for (int i = 0; i < M; ++i) {
		if (dp[x][y] > dp[M][i]) {
			x = M, y = i;
		}
		if (dp[x][y] > dp[i][M]) {
			x = i, y = M;
		}
	}
	cout << dp[x][y] << "\n";
	deque<bool> A(M + 1);
	for (int i = M; i > 0; --i) {
		if (x == i) {
			A[i] = true;
			x = y == i - 1 ? par[x][y] : (x - 1);
		} else {
			y = x == i - 1 ? par[x][y] : (y - 1);
		}
	}
	for (int i = 1; i <= M; ++i) {
		cout << (A[i] ? 1 : 2) << "\n";
	}
	return 0;
}
