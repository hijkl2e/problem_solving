#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int N;
int A[1001][1001];
bool B[1001][1001];
int dp[4][1001][1001];

int solve() {
	for (int k = 0; k < 4; ++k) {
		for (int i = 1; i <= N; ++i) {
			dp[k][0][i] = dp[k][i][0] = -INF;
		}
	}
	dp[0][0][1] = dp[0][1][0] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			int mv1 = -INF;
			for (int k = 0; k < 4; ++k) {
				int mv2 = max(dp[k][i - 1][j], dp[k][i][j - 1]);
				dp[k][i][j] = max(B[i][j] ? mv1 : -INF, mv2) + A[i][j];
				mv1 = mv2;
			}
		}
	}
	return dp[3][N][N];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> A[i][j];
		}
	}
	int P{};
	cin >> P;
	while (P--) {
		int r{}, c{};
		cin >> r >> c;
		B[r][c] = true;
	}
	int ans = max(solve(), -1);
	cout << ans << "\n";
	return 0;
}
