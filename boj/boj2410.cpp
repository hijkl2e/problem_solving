#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> dp(N + 1);
	dp[0] = 1;
	for (int i = 1; i <= N; i *= 2) {
		for (int j = i; j <= N; ++j) {
			dp[j] = (dp[j] + dp[j - i]) % MOD;
		}
	}
	cout << dp[N] << "\n";
	return 0;
}
