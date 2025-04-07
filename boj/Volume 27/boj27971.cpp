#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, a{}, b{};
	cin >> N >> M >> a >> b;
	vector<int> dp(N + 1);
	while (M--) {
		int l{}, r{};
		cin >> l >> r;
		++dp[l], --dp[r + 1];
	}
	partial_sum(dp.begin(), dp.end(), dp.begin());
	for (int i = 1; i <= N; ++i) {
		dp[i] = dp[i] ? -1 : INF;
	}
	for (int i = 0; i < N; ++i) {
		if (dp[i] == INF || dp[i] == -1) {
			continue;
		}
		if (i + a <= N && dp[i + a] != -1) {
			dp[i + a] = min(dp[i + a], dp[i] + 1);
		}
		if (i + b <= N && dp[i + b] != -1) {
			dp[i + b] = min(dp[i + b], dp[i] + 1);
		}
	}
	cout << (dp[N] == INF ? -1 : dp[N]) << "\n";
	return 0;
}
