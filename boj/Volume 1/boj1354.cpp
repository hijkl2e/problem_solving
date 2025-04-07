#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll P, Q, X, Y;
vector<int> dp(3e6);

ll solve(ll x) {
	if (x <= 0) {
		return 1;
	} else if (x < dp.size()) {
		return dp[x];
	}
	return solve(x / P - X) + solve(x / Q - Y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N >> P >> Q >> X >> Y;
	dp[0] = 1;
	for (int i = 1; i < dp.size(); ++i) {
		dp[i] = dp[max(i / P - X, 0LL)] + dp[max(i / Q - Y, 0LL)];
	}
	cout << solve(N) << "\n";
	return 0;
}
