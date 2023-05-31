#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<deque<bool>> B(N, deque<bool>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (A[i] == A[j]) {
				B[i][j] = true;
			}
		}
	}
	vector<vector<int>> dp(N, vector<int>(N));
	for (int l = 1; l < N; ++l) {
		for (int i = 0; i + l < N; ++i) {
			int j = i + l;
			dp[i][j] = (N > 2 ? dp[i + 1][j - 1] : 0) + B[i][j];
			for (int k = i; k < j; ++k) {
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
			}
		}
	}
	cout << dp[0][N - 1] << "\n";
	return 0;
}
