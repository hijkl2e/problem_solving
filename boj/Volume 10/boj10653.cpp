#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int dist(int x1, int y1, int x2, int y2) {
	return abs(x2 - x1) + abs(y2 - y1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> x(N);
	vector<int> y(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i] >> y[i];
	}
	vector<vector<int>> dp(N, vector<int>(K + 1, INF));
	dp[0][0] = 0;
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j <= K; ++j) {
			for (int k = 1; i + k < N && j + k - 1 <= K; ++k) {
				dp[i + k][j + k - 1] = min(dp[i + k][j + k - 1],
							dp[i][j] + dist(x[i], y[i], x[i + k], y[i + k]));
			}
		}
	}
	int ans = *min_element(dp[N - 1].begin(), dp[N - 1].end());
	cout << ans << "\n";
	return 0;
}
