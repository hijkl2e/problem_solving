#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> dp;

void dfs(int x, int p) {
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		dfs(y, x);
		dp[x] += dp[y];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, R{}, Q{};
	cin >> N >> R >> Q;
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dp.assign(N + 1, 1);
	dfs(R, -1);
	while (Q--) {
		int x{};
		cin >> x;
		cout << dp[x] << "\n";
	}
	return 0;
}
