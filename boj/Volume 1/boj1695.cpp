#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<vector<int>> dp(N, vector<int>(N));
	for (int i = N - 2; i >= 0; --i) {
		for (int j = i + 1; j < N; ++j) {
			dp[i][j] = A[i] == A[j] ? dp[i + 1][j - 1] : (min(dp[i][j - 1], dp[i + 1][j]) + 1);
		}
	}
	cout << dp[0][N - 1] << "\n";
	return 0;
}
