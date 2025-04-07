#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<deque<bool>> dp(N + 1, deque<bool>(7));
	dp[0][0] = true;
	for (int i = 1; i <= N; ++i) {
		copy(dp[i - 1].begin(), dp[i - 1].end(), dp[i].begin());
		for (int j = 0; j < 7; ++j) {
			if (dp[i - 1][j]) {
				dp[i][(j + A[i]) % 7] = true;
			}
		}
	}
	cout << (dp[N][4] ? "YES" : "NO") << "\n";
	return 0;
}
