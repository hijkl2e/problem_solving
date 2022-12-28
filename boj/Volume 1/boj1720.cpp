#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> dp(N + 1);
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= N; ++i) {
		dp[i] = dp[i - 1] + 2 * dp[i - 2];
	}
	int ans = dp[N / 2] + (N % 2 == 0 ? 2 * dp[N / 2 - 1] : 0);
	ans += (dp[N] - ans) / 2;
	cout << ans << "\n";
	return 0;
}
