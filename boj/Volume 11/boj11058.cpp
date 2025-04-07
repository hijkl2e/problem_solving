#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> dp(N + 1);
	for (int i = 1; i <= N; ++i) {
		dp[i] = max(dp[i], dp[i - 1] + 1);
		for (int j = i + 3; j <= N; ++j) {
			dp[j] = max(dp[j], (j - i - 1) * dp[i]);
		}
	}
	cout << dp[N] << "\n";
	return 0;
}
