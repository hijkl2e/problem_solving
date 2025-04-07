#include <bits/stdc++.h>

using namespace std;

int dp[9][4][26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(6);
	for (int i = 0; i < 6; i += 2) {
		cin >> A[i];
	}
	for (int i = 1; i < 6; i += 2) {
		cin >> A[i];
	}
	dp[0][3][0] = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k <= M; ++k) {
				for (int l = 0; l < 6; ++l) {
					int m = min(k + A[l] / (j == l / 2 ? 2 : 1), M);
					dp[i + 1][l / 2][m] += dp[i][j][k];
				}
			}
		}
	}
	int ans{};
	for (int i = 0; i < 3; ++i) {
		ans += dp[N][i][M];
	}
	cout << ans << "\n";
	return 0;
}
