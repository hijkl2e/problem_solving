#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, D{};
	cin >> N >> D;
	vector<vector<ii>> G(D + 1);
	while (N--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		if (v <= D) {
			G[v].push_back({u, w});
		}
	}
	vector<int> dp(D + 1);
	for (int i = 1; i <= D; ++i) {
		dp[i] = dp[i - 1] + 1;
		for (auto &[u, w] : G[i]) {
			dp[i] = min(dp[i], dp[u] + w);
		}
	}
	cout << dp[D] << "\n";
	return 0;
}
