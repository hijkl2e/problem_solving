#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int F{};
	cin >> F;
	bool yes = true;
	while (F--) {
		int T{}, N{};
		cin >> T >> N;
		vector<deque<bool>> dp(2, deque<bool>(T + 1));
		fill(dp[0].begin(), dp[0].end(), true);
		for (int i = 1; i <= N; ++i) {
			int t1{}, t2{};
			cin >> t1 >> t2;
			int t = t2 - t1;
			int ii = i % 2;
			fill(dp[ii].begin(), dp[ii].end(), false);
			for (int j = 0; j <= T; ++j) {
				if (j + t <= T) {
					dp[ii][j + t] |= dp[1 - ii][j];
				}
				if (j - t >= 0) {
					dp[ii][j - t] |= dp[1 - ii][j];
				}
			}
		}
		yes &= accumulate(dp[N % 2].begin(), dp[N % 2].end(), 0) > 0;
	}
	cout << (yes ? "possible" : "impossible") << "\n";
	return 0;
}
