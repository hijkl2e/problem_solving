#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	for (int tc = 1; cin >> N, N; ++tc) {
		vector<vector<int>> A(N, vector<int>(3));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < 3; ++j) {
				cin >> A[i][j];
			}
		}
		vector<vector<int>> dp(N, vector<int>(3, INF));
		dp[0][1] = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < 3; ++j) {
				dp[i][j] += A[i][j];
				if (j + 1 < 3) {
					dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
				}
				if (i == N - 1) {
					continue;
				}
				for (int k = 0; k < 3; ++k) {
					if (abs(j - k) == 2) {
						continue;
					}
					dp[i + 1][k] = min(dp[i + 1][k], dp[i][j]);
				}
			}
		}
		cout << tc << ". " << dp[N - 1][1] << "\n";
	}
	return 0;
}
