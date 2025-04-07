#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, a{}, b{}, X{}, Y{};
	cin >> N >> M >> a >> b >> X >> Y;
	vector<int> A(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i];
	}
	vector<vector<int>> dp(M + 2, vector<int>(N + 1, INF));
	dp[0][a] = 0;
	for (int i = 0; i <= M; ++i) {
		for (int j = 1; j <= N; ++j) {
			for (int k = 1; k <= N; ++k) {
				dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + abs(j - k) * Y);
			}
		}
		if (i == M) {
			break;
		}
		int x = dp[i + 1][A[i]], y = dp[i + 1][A[i] + 1];
		dp[i + 1][A[i]] = min(y, x + X);
		dp[i + 1][A[i] + 1] = min(x, y + X);
	}
	cout << dp.back()[b] << "\n";
	return 0;
}
