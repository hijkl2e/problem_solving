#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<ll> dp(101);
	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = 2;
	for (int i = 5; i < dp.size(); ++i) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cout << dp[N] << "\n";
	}
	return 0;
}
