#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<vector<int>> G;
vector<int> dep, par, top;
vector<ll> sz, dp;

void dfs1(int u) {
	sz[u] = 1;
	for (auto &v : G[u]) {
		if (par[u] == v) {
			continue;
		}
		dep[v] = dep[u] + 1;
		par[v] = u;
		dfs1(v);
		dp[u] += (sz[u] - 1) * sz[v];
		sz[u] += sz[v];
		if (sz[v] > sz[G[u][0]]) {
			swap(v, G[u][0]);
		}
	}
}

void dfs2(int u) {
	for (int v : G[u]) {
		if (par[u] == v) {
			continue;
		}
		top[v] = v == G[u][0] ? top[u] : v;
		dfs2(v);
	}
}

int lca(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) {
			swap(u, v);
		}
		v = par[top[v]];
	}
	return dep[u] < dep[v] ? u : v;
}

int solve(int u, int v) {
	int prev{};
	while (top[u] != top[v]) {
		prev = top[v];
		v = par[top[v]];
	}
	return u == v ? prev : G[u][0];
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
	sz.resize(N + 1);
	dep.resize(N + 1);
	par.resize(N + 1);
	top.resize(N + 1);
	dp.resize(N + 1);
	int r = 1;
	par[r] = -1;
	top[r] = 1;
	dfs1(r);
	dfs2(r);
	while (Q--) {
		int q{}, x{};
		cin >> q >> x;
		if (q == 1) {
			r = x;
			continue;
		}
		ll ans{};
		if (x == r) {
			ans = (N - 1) + dp[x] + (sz[x] - 1) * (N - sz[x]);
		} else if (x == lca(x, r)) {
			int u = solve(x, r);
			ans = (N - sz[u] - 1) + dp[x] + (sz[x] - sz[u] - 1) * (N - sz[x] - sz[u]);
		} else {
			ans = (sz[x] - 1) + dp[x];
		}
		cout << ans << "\n";
	}
	return 0;
}
