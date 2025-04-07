#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> dp(N + 1, 1e9);
	dp[N] = 0;
	for (int i = N; i > 1; --i) {
		if (i % 3 == 0) {
			dp[i / 3] = min(dp[i / 3], dp[i] + 1);
		}
		if (i % 2 == 0) {
			dp[i / 2] = min(dp[i / 2], dp[i] + 1);
		}
		dp[i - 1] = min(dp[i - 1], dp[i] + 1);
	}
	cout << dp[1] << "\n";
	return 0;
}
