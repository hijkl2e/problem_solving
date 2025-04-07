#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<ll> dp(1001, INF);
	dp[0] = 0;
	for (int i = 1; i < dp.size(); ++i) {
		for (int j = min(i, 62); j > 0; --j) {
			dp[i] = min(dp[i], 2 * dp[i - j] + (1LL << j) - 1);
		}
	}
	int N{};
	for (int tc = 1; cin >> N; ++tc) {
		cout << "Case " << tc << ": " << dp[N] << "\n";
	}
	return 0;
}
