#include <bits/stdc++.h>

using namespace std;

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
	vector<vector<int>> dp(N + 1, vector<int>(M + 1));
	int ans{};
	for (int i = N - 1; i >= 0; --i) {
		for (int j = M - 1; j >= 0; --j) {
			if (A[i][j]) {
				continue;
			}
			dp[i][j] = min({dp[i][j + 1], dp[i + 1][j], dp[i + 1][j + 1]}) + 1;
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << "\n";
	return 0;
}
