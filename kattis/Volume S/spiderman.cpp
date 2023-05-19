#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		vector<vector<int>> dp(N + 1, vector<int>(501, INF));
		dp[0][0] = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < 501; ++j) {
				if (dp[i][j] == INF) {
					continue;
				}
				if (j + A[i] < 501) {
					int &val = dp[i + 1][j + A[i]];
					val = min(val, max(dp[i][j], j + A[i]));
				}
				if (j - A[i] >= 0) {
					int &val = dp[i + 1][j - A[i]];
					val = min(val, dp[i][j]);
				}
			}
		}
		if (dp[N][0] == INF) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		string ans;
		for (int i = N - 1, j = 0; i >= 0; --i) {
			if (j + A[i] < 501 && dp[i][j + A[i]] == dp[i + 1][j]) {
				ans += 'D';
				j += A[i];
			} else {
				ans += 'U';
				j -= A[i];
			}
		}
		reverse(ans.begin(), ans.end());
		cout << ans << "\n";
	}
	return 0;
}
