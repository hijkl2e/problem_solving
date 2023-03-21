#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		cin.ignore();
		vector<string> A(N);
		for (int i = 0; i < N; ++i) {
			getline(cin, A[i]);
		}
		vector<int> B;
		for (int i = 0; i < (1 << M); ++i) {
			bool flag = true;
			for (int j = 0; j < M; ++j) {
				if (((i >> j) & 3) == 3) {
					flag = false;
					break;
				}
			}
			if (flag) {
				B.push_back(i);
			}
		}
		vector<vector<int>> dp(N + 1, vector<int>(1 << M, -INF));
		dp[0][0] = 0;
		for (int i = 0; i < N; ++i) {
			for (int x : B) {
				bool flag{};
				for (int j = 0; j < M; ++j) {
					if ((x & (1 << j)) && A[i][j] == 'x') {
						flag = true;
						break;
					}
				}
				if (flag) {
					continue;
				}
				for (int y : B) {
					if (dp[i][y] == -INF || ((x << 1) & y) || ((y << 1) & x)) {
						continue;
					}
					dp[i + 1][x] = max(dp[i + 1][x], dp[i][y] + __builtin_popcount(x));
				}
			}
		}
		int ans = *max_element(dp[N].begin(), dp[N].end());
		cout << ans << "\n";
	}
	return 0;
}
