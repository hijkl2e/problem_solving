#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<ll> dp(2501);
	dp[0] = 1;
	for (int i = 1; i < dp.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			dp[i] = (dp[i] + dp[j] * dp[i - j - 1]) % MOD;
		}
	}
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cout << (N % 2 ? 0 : dp[N / 2]) << "\n";
	}
	return 0;
}
