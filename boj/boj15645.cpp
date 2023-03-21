#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int N;
vector<vector<int>> A;

int solve() {
	vector<vector<int>> dp(N + 1, vector<int>(3));
	for (int i = 1; i <= N; ++i) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + A[i][0];
		dp[i][1] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + A[i][1];
		dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + A[i][2];
	}
	return max({dp[N][0], dp[N][1], dp[N][2]});
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.assign(N + 1, vector<int>(3));
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> A[i][j];
		}
	}
	int maxv = solve();
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < 3; ++j) {
			A[i][j] *= -1;
		}
	}
	int minv = -solve();
	cout << maxv << " " << minv << "\n";
	return 0;
}
