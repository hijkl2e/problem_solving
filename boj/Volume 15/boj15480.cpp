#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> d;
vector<vector<int>> par;

void dfs(int u) {
	for (int v : G[u]) {
		if (v == par[0][u]) {
			continue;
		}
		d[v] = d[u] + 1;
		par[0][v] = u;
		dfs(v);
	}
}

int lca(int u, int v) {
	if (d[u] > d[v]) {
		swap(u, v);
	}
	while (d[v] - d[u]) {
		int x = __builtin_ctz(d[v] - d[u]);
		v = par[x][v];
	}
	if (u == v) {
		return u;
	}
	for (int i = 16; i >= 0; --i) {
		if (par[i][u] != par[i][v]) {
			u = par[i][u];
			v = par[i][v];
		}
	}
	return par[0][u];
}

int solve(int u, int s) {
	while (s) {
		int x = __builtin_ctz(s);
		u = par[x][u];
		s &= ~(1 << x);
	}
	return u;
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
	d.resize(N + 1);
	par.assign(17, vector<int>(N + 1));
	dfs(1);
	for (int i = 1; i < 17; ++i) {
		for (int j = 1; j <= N; ++j) {
			par[i][j] = par[i - 1][par[i - 1][j]];
		}
	}
	int M{};
	cin >> M;
	while (M--) {
		int r{}, u{}, v{};
		cin >> r >> u >> v;
		if (d[u] > d[v]) {
			swap(u, v);
		}
		int l1 = lca(u, v);
		int l2 = lca(u, r);
		int l3 = lca(v, r);
		int ans = d[l3] > d[l1] ? l3 : d[l2] > d[l1] ? l2 : l1;
		cout << ans << "\n";
	}
	return 0;
}
