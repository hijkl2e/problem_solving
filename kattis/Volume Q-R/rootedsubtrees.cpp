#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<vector<int>> G;
vector<int> sz, dep, par, top;

void dfs1(int u) {
	sz[u] = 1;
	for (auto &v : G[u]) {
		if (par[u] == v) {
			continue;
		}
		dep[v] = dep[u] + 1;
		par[v] = u;
		dfs1(v);
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
	par[1] = -1;
	top[1] = 1;
	dfs1(1);
	dfs2(1);
	while (Q--) {
		int u{}, v{};
		cin >> u >> v;
		int l = lca(u, v);
		ll cnt = dep[u] + dep[v] - 2 * dep[l] + 1;
		ll ans = N - cnt + cnt * (cnt + 1) / 2;
		cout << ans << "\n";
	}
	return 0;
}
