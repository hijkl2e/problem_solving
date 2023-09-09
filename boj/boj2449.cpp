#include <bits/stdc++.h>

using namespace std;

int dp[201][201][21];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	memset(dp, 0x3f, sizeof dp);
	for (int i = N - 1; i >= 0; --i) {
		for (int j = 1; j <= K; ++j) {
			dp[i][i][j] = A[i] != j;
		}
		for (int j = i + 1; j < N; ++j) {
			for (int k = 1; k <= K; ++k) {
				for (int l = i; l < j; ++l) {
					dp[i][j][k] = min(dp[i][j][k], dp[i][l][k] + dp[l + 1][j][k]);
				}
			}
			int minv = *min_element(dp[i][j], dp[i][j + 1]);
			for (int k = 1; k <= K; ++k) {
				dp[i][j][k] = min(dp[i][j][k], minv + 1);
			}
		}
	}
	int ans = *min_element(dp[0][N - 1], dp[0][N]);
	cout << ans << "\n";
	return 0;
}
