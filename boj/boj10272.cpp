#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

double dist(int x1, int y1, int x2, int y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> x(N);
		vector<int> y(N);
		for (int i = 0; i < N; ++i) {
			cin >> x[i] >> y[i];
		}
		vector<vector<double>> dp(N, vector<double>(N, INF));
		dp[0][0] = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j <= i; ++j) {
				if (i - j < 2) {
					for (int k = 0; k < i; ++k) {
						dp[i][j] = min(dp[i][j], dp[j][k] + dist(x[k], y[k], x[i], y[i]));
					}
				} else {
					dp[i][j] = dp[i - 1][j] + dist(x[i - 1], y[i - 1], x[i], y[i]);
				}
			}
		}
		cout << fixed << setprecision(10);
		cout << dp[N - 1][N - 1] << "\n";
	}
	return 0;
}
