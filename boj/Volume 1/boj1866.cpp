#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(10001);
	while (N--) {
		int x{};
		cin >> x;
		++A[x];
	}
	partial_sum(A.begin(), A.end(), A.begin());
	ll T{}, H{};
	cin >> T >> H;
	vector<ll> dp(10001, INF);
	dp[0] = 0;
	for (int i = 0; i < dp.size(); ++i) {
		ll x{};
		for (int j = i + 1; j < dp.size(); ++j) {
			x += A[j - 1] - A[i + (j - i - 1) / 2];
			dp[j] = min(dp[j], dp[i] + T * x + H);
		}
	}
	ll ans = INF, x{};
	for (int i = dp.size() - 1; i >= 0; --i) {
		x += A.back() - A[i];
		ans = min(ans, dp[i] + T * x);
	}
	cout << ans << "\n";
	return 0;
}
