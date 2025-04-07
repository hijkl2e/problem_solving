#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> dp(100);
	for (int i = 1; i < 100; ++i) {
		dp[i] = dp[i - 1] + 1;
		if (i >= 10) {
			dp[i] = min(dp[i], dp[i - 10] + 1);
		}
		if (i >= 25) {
			dp[i] = min(dp[i], dp[i - 25] + 1);
		}
	}
	int T{};
	cin >> T;
	while (T--) {
		ll N{};
		cin >> N;
		int ans{};
		while (N) {
			int r = N % 100;
			ans += dp[r];
			N /= 100;
		}
		cout << ans << "\n";
	}
	return 0;
}
