#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> sz, dp;

void dfs(int x, int p) {
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		dfs(y, x);
		sz[x] += sz[y];
		dp[x] += dp[y];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		G.assign(N + 1, {});
		dp.assign(N + 1, 0);
		for (int i = 0; i < N; ++i) {
			int u{}, m{}, d{};
			cin >> u >> m >> d;
			dp[u] = m;
			while (d--) {
				int v{};
				cin >> v;
				G[u].push_back(v);
				G[v].push_back(u);
			}
		}
		sz.assign(N + 1, 1);
		dfs(1, -1);
		int ans{};
		for (int i = 1; i <= N; ++i) {
			ans += abs(sz[i] - dp[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}
