#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> nCr(31, vector<int>(31));
	for (int i = 0; i < 31; ++i) {
		nCr[i][0] = nCr[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			nCr[i][j] = nCr[i - 1][j] + nCr[i - 1][j - 1];
		}
	}
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int M{};
		cin >> M;
		vector<int> A(M);
		for (int i = 0; i < M; ++i) {
			cin >> A[i];
		}
		int N{}, T{};
		cin >> N >> T;
		vector<vector<int>> dp(N + 1, vector<int>(T + 1));
		dp[0][0] = 1;
		for (int i = 0; i < M; ++i) {
			for (int j = N; j > 0; --j) {
				for (int k = T; k >= A[i]; --k) {
					dp[j][k] += dp[j - 1][k - A[i]];
				}
			}
		}
		cout << "Game " << tc << " -- " << dp[N][T] << " : " << (nCr[M][N] - dp[N][T]) << "\n";
	}
	return 0;
}
