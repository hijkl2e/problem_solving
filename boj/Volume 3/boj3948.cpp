#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<ll> dp(21);
	dp[0] = 1;
	for (int i = 1; i < dp.size(); ++i) {
		for (int j = 0, k = 1; j < i; ++j) {
			dp[i] += k * max(dp[j] / 2, 1LL) * max(dp[i - j - 1] / 2, 1LL);
			k = k * (i - j - 1) / (j + 1);
		}
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
