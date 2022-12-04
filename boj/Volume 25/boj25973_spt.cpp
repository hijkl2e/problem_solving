#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<vector<int>> G, par;
vector<int> dep;
vector<ll> sz, dp;

void dfs(int u) {
	sz[u] = 1;
	for (auto &v : G[u]) {
		if (par[u][0] == v) {
			continue;
		}
		dep[v] = dep[u] + 1;
		par[v][0] = u;
		dfs(v);
		dp[u] += (sz[u] - 1) * sz[v];
		sz[u] += sz[v];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	par.assign(N + 1, vector<int>(20));
	dep.resize(N + 1);
	sz.resize(N + 1);
	dp.resize(N + 1);
	dfs(1);
	for (int j = 1; j < 20; ++j) {
		for (int i = 1; i <= N; ++i) {
			par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
	int r = 1;
	while (Q--) {
		int q{}, x{};
		cin >> q >> x;
		if (q == 1) {
			r = x;
			continue;
		}
		ll ans{};
		int u = r;
		if (dep[x] + 1 < dep[u]) {
			int df = dep[u] - dep[x] - 1;
			for (int i = 19; i >= 0; --i) {
				if (df & (1 << i)) {
					u = par[u][i];
				}
			}
		}
		if (x == r) {
			ans = (N - 1) + dp[x] + (sz[x] - 1) * (N - sz[x]);
		} else if (par[u][0] == x) {
			ans = (N - sz[u] - 1) + dp[x] + (sz[x] - sz[u] - 1) * (N - sz[x] - sz[u]);
		} else {
			ans = (sz[x] - 1) + dp[x];
		}
		cout << ans << "\n";
	}
	return 0;
}
