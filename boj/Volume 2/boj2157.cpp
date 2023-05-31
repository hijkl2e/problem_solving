#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<vector<ii>> G(N + 1);
	while (K--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		if (u < v) {
			G[u].push_back({v, w});
		}
	}
	vector<vector<int>> dp(M + 1, vector<int>(N + 1, -INF));
	dp[1][1] = 0;
	for (int i = 1; i < M; ++i) {
		for (int u = 1; u <= N; ++u) {
			for (auto &[v, w] : G[u]) {
				dp[i + 1][v] = max(dp[i + 1][v], dp[i][u] + w);
			}
		}
	}
	int ans{};
	for (int i = 1; i <= M; ++i) {
		ans = max(ans, dp[i][N]);
	}
	cout << ans << "\n";
	return 0;
}
