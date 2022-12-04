#include <bits/stdc++.h>

using namespace std;

const int dx[5]{1, 0, -1, 0, 0};
const int dy[5]{0, -1, 0, 1, 0};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, T{};
	cin >> N >> T;
	T *= 2;
	vector<int> X(N + 1);
	vector<int> Y(N + 1);
	vector<int> C(N + 1);
	vector<int> D(N + 1);
	D[0] = 4;
	for (int i = 1; i <= N; ++i) {
		cin >> X[i] >> Y[i] >> C[i] >> D[i];
		X[i] *= 2;
		Y[i] *= 2;
	}
	vector<vector<int>> dp(T + 1, vector<int>(N + 1, -1));
	dp[0][0] = 0;
	for (int i = 0; i < T; ++i) {
		for (int j = 0; j <= N; ++j) {
			if (dp[i][j] == -1) {
				continue;
			}
			int x = X[j] + (i - 2) * dx[D[j]];
			int y = Y[j] + (i - 2) * dy[D[j]];
			for (int k = 1; k <= N; ++k) {
				if (j == k) {
					continue;
				}
				int nt = i + (D[k] % 2 ? abs(X[k] - x) : abs(Y[k] - y));
				int nx = X[k] + nt * dx[D[k]];
				int ny = Y[k] + nt * dy[D[k]];
				if ((dx[D[k]] && (x - nx) && (dx[D[k]] ^ (x - nx)) < 0)
						|| (dy[D[k]] && (y - ny) && (dy[D[k]] ^ (y - ny)) < 0)) {
					continue;
				}
				nt += (D[k] % 2 ? abs(y - ny) : abs(x - nx)) / 2 + 2;
				if (nt <= T) {
					dp[nt][k] = max(dp[nt][k], dp[i][j] + C[k]);
				}
			}
		}
	}
	int ans{};
	for (int i = 0; i <= T; ++i) {
		for (int j = 0; j <= N; ++j) {
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << "\n";
	return 0;
}
