#include <bits/stdc++.h>

using namespace std;

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
	vector<vector<int>> dp(N + 1, vector<int>(M + 1));
	for (int i = N - 1; i >= 0; --i) {
		for (int j = M - 1; j >= 0; --j) {
			if (A[i][j] == '1') {
				dp[i][j] = min({dp[i][j + 1], dp[i + 1][j], dp[i + 1][j + 1]}) + 1;
			}
		}
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			ans = max(ans, dp[i][j]);
		}
	}
	ans *= ans;
	cout << ans << "\n";
	return 0;
}
