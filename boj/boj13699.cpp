#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> dp(N + 1);
	dp[0] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < i; ++j) {
			dp[i] += dp[j] * dp[i - j - 1];
		}
	}
	cout << dp[N] << "\n";
	return 0;
}
