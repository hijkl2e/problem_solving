#include <bits/stdc++.h>

using namespace std;

const int MOD = 9901;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> dp(N + 1);
	dp[0] = 1, dp[1] = 3;
	for (int i = 2; i <= N; ++i) {
		dp[i] = (2 * dp[i - 1] + dp[i - 2]) % MOD;
	}
	cout << dp[N] << "\n";
	return 0;
}
