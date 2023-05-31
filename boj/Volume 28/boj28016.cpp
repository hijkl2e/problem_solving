#include <bits/stdc++.h>

using namespace std;

using ll = __int128;

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
	vector<vector<ll>> dp(N, vector<ll>(M));
	int s = find(A[0].begin(), A[0].end(), 2) - A[0].begin();
	dp[0][s] = static_cast<ll>(1) << (N - 1);
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i + 1][j] == 0) {
				dp[i + 1][j] += dp[i][j];
				continue;
			}
			if (j && A[i][j - 1] + A[i + 1][j - 1] == 0) {
				dp[i + 1][j - 1] += dp[i][j] / 2;
			}
			if (j + 1 < M && A[i][j + 1] + A[i + 1][j + 1] == 0) {
				dp[i + 1][j + 1] += dp[i][j] / 2;
			}
		}
	}
	int p = max_element(dp[N - 1].begin(), dp[N - 1].end()) - dp[N - 1].begin();
	cout << (dp[N - 1][p] ? p : -1) << "\n";
	return 0;
}
