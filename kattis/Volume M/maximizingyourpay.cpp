#include <bits/stdc++.h>

using namespace std;

int N;
vector<deque<bool>> G;
vector<vector<int>> dp;

int solve(int u, int x) {
	if (dp[u][x] != -1) {
		return dp[u][x];
	}
	int &val = dp[u][x];
	val = G[u][0];
	for (int i = 0; i < N; ++i) {
		if ((x & (1 << i)) && G[u][i]) {
			int res = solve(i, x & ~(1 << i));
			if (res) {
				val = max(val, res + 1);
			}
		}
	}
	return val;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{};
	while (cin >> N >> M) {
		G.assign(N, deque<bool>(N));
		while (M--) {
			int u{}, v{};
			cin >> u >> v;
			G[u][v] = G[v][u] = true;
		}
		G[0][0] = true;
		dp.assign(N, vector<int>(1 << N, -1));
		cout << solve(0, (1 << N) - 2) << "\n";
	}
	return 0;
}
