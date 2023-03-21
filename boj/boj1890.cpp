#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<ll>> dp(N, vector<ll>(N));
	dp[0][0] = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] == 0) {
				continue;
			}
			if (j + A[i][j] < N) {
				dp[i][j + A[i][j]] += dp[i][j];
			}
			if (i + A[i][j] < N) {
				dp[i + A[i][j]][j] += dp[i][j];
			}
		}
	}
	cout << dp[N - 1][N - 1] << "\n";
	return 0;
}
