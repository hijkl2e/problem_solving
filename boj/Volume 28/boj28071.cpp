#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<vector<int>> dp(M + 1, vector<int>(K, -INF));
	dp[0][0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			for (int k = 0; k < K; ++k) {
				int &val = dp[j + 1][(k + A[i]) % K];
				val = max(val, dp[j][k] + A[i]);
			}
		}
	}
	int ans{};
	for (int i = 0; i <= M; ++i) {
		ans = max(ans, dp[i][0]);
	}
	cout << ans << "\n";
	return 0;
}
