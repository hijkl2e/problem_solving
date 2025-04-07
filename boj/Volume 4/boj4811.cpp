#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<ll> dp(31);
	dp[0] = 1;
	for (int i = 1; i < 31; ++i) {
		for (int j = 0; j < i; ++j) {
			dp[i] += dp[j] * dp[i - j - 1];
		}
	}
	int N{};
	while (cin >> N, N) {
		cout << dp[N] << "\n";
	}
	return 0;
}
