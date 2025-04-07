#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> dp(N + 1);
	dp[0] = 1;
	for (int i = 1; i <= N; ++i) {
		dp[i] = dp[i - 1];
		if (i >= M) {
			dp[i] = (dp[i] + dp[i - M]) % MOD;
		}
	}
	cout << dp[N] << "\n";
	return 0;
}
