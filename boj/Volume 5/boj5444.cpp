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
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		vector<vector<int>> dp(2, vector<int>(M, INF));
		dp[1][0] = 0;
		for (int i = 0; i < N; ++i) {
			copy(dp[1].begin(), dp[1].end(), dp[0].begin());
			for (int j = 0; j < M; ++j) {
				int x = (j + A[i]) % M;
				dp[1][x] = min(dp[1][x], dp[0][j] + 1);
			}
		}
		int x = accumulate(A.begin(), A.end(), 0) % M;
		int ans = N - dp[1][x];
		cout << ans << "\n";
	}
	return 0;
}
