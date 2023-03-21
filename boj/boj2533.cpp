#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G, dp;

void dfs(int x, int p) {
	dp[x][1] = 1;
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		dfs(y, x);
		dp[x][0] += dp[y][1];
		dp[x][1] += min(dp[y][0], dp[y][1]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dp.assign(N + 1, vector<int>(2));
	dfs(1, -1);
	int ans = min(dp[1][0], dp[1][1]);
	cout << ans << "\n";
	return 0;
}
