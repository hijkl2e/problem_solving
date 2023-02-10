#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 2);
	for (int i = 1; i < N + 2; ++i) {
		cin >> A[i];
		if (1 < i && i < N + 1) {
			cin >> A[i];
		}
	}
	vector<vector<int>> dp(N + 1, vector<int>(N + 2, INF));
	for (int i = 1; i <= N; ++i) {
		dp[i][i + 1] = 0;
	}
	for (int i = N - 1; i > 0; --i) {
		for (int j = i + 2; j < N + 2; ++j) {
			for (int k = i + 1; k < j; ++k) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[k] * A[j]);
			}
		}
	}
	cout << dp[1][N + 1] << "\n";
	return 0;
}
