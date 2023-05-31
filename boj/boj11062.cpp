#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N + 1);
		for (int i = 1; i <= N; ++i) {
			cin >> A[i];
		}
		vector<int> B(A.begin(), A.end());
		partial_sum(B.begin(), B.end(), B.begin());
		vector<vector<int>> dp(N + 1, vector<int>(N + 1));
		for (int i = N; i > 0; --i) {
			dp[i][i] = A[i];
			for (int j = i + 1; j <= N; ++j) {
				dp[i][j] = B[j] - B[i - 1] - min(dp[i + 1][j], dp[i][j - 1]);
			}
		}
		cout << dp[1][N] << "\n";
	}
	return 0;
}
