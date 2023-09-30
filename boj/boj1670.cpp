#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 987654321;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	N /= 2;
	vector<ll> dp(N + 1);
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j < i; ++j) {
			dp[i] = (dp[i] + dp[j] * dp[i - j - 1]) % MOD;
		}
	}
	cout << dp[N] << "\n";
	return 0;
}
