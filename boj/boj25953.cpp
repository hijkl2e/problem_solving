#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, T{}, M{};
	cin >> N >> T >> M;
	int s{}, e{};
	cin >> s >> e;
	vector<vector<int>> dp(2, vector<int>(N, INF));
	dp[1][s] = 0;
	for (int i = 0; i < T; ++i) {
		copy(dp[1].begin(), dp[1].end(), dp[0].begin());
		for (int j = 0; j < M; ++j) {
			int u{}, v{}, w{};
			cin >> u >> v >> w;
			if (dp[0][u] < INF) {
				dp[1][v] = min(dp[1][v], dp[0][u] + w);
			}
			if (dp[0][v] < INF) {
				dp[1][u] = min(dp[1][u], dp[0][v] + w);
			}
		}
	}
	cout << (dp[1][e] == INF ? -1 : dp[1][e]) << "\n";
	return 0;
}
