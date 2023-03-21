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
		vector<int> A(N + 2);
		vector<int> B(N + 2);
		for (int i = 1; i <= N; ++i) {
			cin >> A[i];
		}
		for (int i = 1; i <= N; ++i) {
			cin >> B[i];
		}
		if (N == 1) {
			cout << (A[1] + B[1] <= M ? 1 : 2) << "\n";
			continue;
		}
		A.back() = A[1];
		B.back() = B[1];
		vector<vector<int>> dp(N + 2, vector<int>(3));
		int ans = INF;
		for (int k = 2; k < 6; ++k) {
			dp[0][2] = dp[1][0] = dp[1][1] = dp[1][2] = INF;
			dp[k / 3][k % 3] = 0;
			for (int i = 2; i < dp.size(); ++i) {
				dp[i][2] = dp[i - 1][2] + (A[i] + B[i] <= M ? 1 : 2);
				dp[i][2] = min(dp[i][2], A[i - 1] + A[i] <= M ? dp[i - 1][1] + 2 : INF);
				dp[i][2] = min(dp[i][2], B[i - 1] + B[i] <= M ? dp[i - 1][0] + 2 : INF);
				dp[i][2] = min(dp[i][2], A[i - 1] + A[i] <= M && B[i - 1] + B[i] <= M ? dp[i - 2][2] + 2 : INF);
				dp[i][0] = min(dp[i - 1][2], A[i - 1] + A[i] <= M ? dp[i - 1][1] : INF) + 1;
				dp[i][1] = min(dp[i - 1][2], B[i - 1] + B[i] <= M ? dp[i - 1][0] : INF) + 1;
			}
			ans = min(ans, dp[N + k / 3][k % 3]);
		}
		cout << ans << "\n";
	}
	return 0;
}
