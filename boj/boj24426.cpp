#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int N;
vector<vector<int>> A;

int solve() {
	vector<vector<int>> dp(N + 1, vector<int>(N + 1));
	for (int i = 2; i <= N; ++i) {
		dp[0][i] = dp[i][0] = -INF;
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + A[i][j];
		}
	}
	return dp[N][N];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.assign(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> A[i][j];
		}
	}
	int r{}, c{};
	cin >> r >> c;
	A[r][c] += INF;
	cout << solve() - INF << " ";
	A[r][c] = -INF;
	cout << solve() << "\n";
	return 0;
}
