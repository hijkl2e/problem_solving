#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> dp(N + 3);
	dp[1] = dp[2] = dp[3] = 1;
	for (int i = 4; i <= N; ++i) {
		dp[i] = dp[i - 1] + dp[i - 3];
	}
	cout << dp[N] << "\n";
	return 0;
}
