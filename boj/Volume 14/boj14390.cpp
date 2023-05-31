#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<vector<int>> B(1 << M, vector<int>(1 << M));
	for (int i = 0; i < (1 << M); ++i) {
		for (int j = 0; j < (1 << M); ++j) {
			B[i][j] = __builtin_popcount(j & ~i);
		}
	}
	vector<vector<int>> dp(N + 1, vector<int>(1 << M, INF));
	dp[0][0] = 0;
	for (int i = 0; i < N; ++i) {
		int x{};
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == '#') {
				x |= 1 << j;
			}
		}
		for (int j = 0; j < (1 << M); ++j) {
			if (x & j) {
				continue;
			}
			int cnt{};
			for (int k = 0; k < M; ++k) {
				if (A[i][k] == '.' && (j & (1 << k)) == 0
						&& (k == 0 || (j & (1 << (k - 1))) || A[i][k - 1] == '#')) {
					++cnt;
				}
			}
			for (int k = 0; k < (1 << M); ++k) {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][k] + B[k][j] + cnt);
			}
		}
	}
	int ans = *min_element(dp[N].begin(), dp[N].end());
	cout << ans << "\n";
	return 0;
}
