#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 2);
	for (int i = 2; i < N + 2; ++i) {
		cin >> A[i];
	}
	vector<vector<int>> dp(N + 2, vector<int>(3));
	for (int i = 2; i < N + 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			int minv = min(dp[i - 1][j], A[i]);
			dp[i - 1][j] -= minv, A[i] -= minv;
			dp[i][j + 1] = minv;
		}
		dp[i][0] = A[i];
	}
	int ans{};
	for (int i = 2; i < N + 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			ans += (2 * j + 3) * dp[i][j];
		}
	}
	cout << ans << "\n";
	return 0;
}
