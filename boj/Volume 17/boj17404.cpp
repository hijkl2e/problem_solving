#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N + 1, vector<int>(3));
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> A[i][j];
		}
	}
	int ans = INF;
	vector<vector<int>> dp(N + 1, vector<int>(3));
	for (int k = 0; k < 3; ++k) {
		dp[1][k] = A[1][k];
		dp[1][(k + 1) % 3] = dp[1][(k + 2) % 3] = INF;
		for (int i = 2; i <= N; ++i) {
			for (int j = 0; j < 3; ++j) {
				dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + A[i][j];
			}
		}
		ans = min({ans, dp[N][(k + 1) % 3], dp[N][(k + 2) % 3]});
	}
	cout << ans << "\n";
	return 0;
}
