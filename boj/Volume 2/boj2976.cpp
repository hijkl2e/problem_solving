#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<vector<int>> dp(N, vector<int>(N, INF));
	dp[0][0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = N - 1; j >= 0; --j) {
			if (j + i + 1 < N) {
				int &val = dp[i + 1][j + i + 1];
				val = min(val, dp[i][j] + A[j + i + 1]);
			}
			if (j - i >= 0) {
				int &val = dp[i][j - i];
				val = min(val, dp[i][j] + A[j - i]);
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < N; ++i) {
		ans = min(ans, dp[i][N - 1]);
	}
	cout << ans << "\n";
	return 0;
}
