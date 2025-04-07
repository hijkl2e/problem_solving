#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

ll N, R, P;
vector<ll> dp;

ll solve(int x) {
	if (dp[x] != INF) {
		return dp[x];
	}
	for (int i = 1; i < x;) {
		int k = (x - 1) / (i + 1) + 1;
		dp[x] = min(dp[x], i * P + R + solve(k));
		if (k == 1) {
			break;
		}
		i += (x - 1) / (k - 1) - i;
	}
	return dp[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> R >> P;
	dp.resize(N + 1, INF);
	dp[1] = 0;
	cout << solve(N) << "\n";
	return 0;
}
