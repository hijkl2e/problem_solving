#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

vector<vector<ii>> G;
vector<int> d;
vector<vector<int>> par;
vector<vector<ll>> c;

void dfs(int u) {
	for (auto &[v, w] : G[u]) {
		if (v == par[0][u]) {
			continue;
		}
		d[v] = d[u] + 1;
		par[0][v] = u;
		c[0][v] = w;
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

ii solve(int u, int s) {
	ll ret{};
	while (s) {
		int x = __builtin_ctz(s);
		ret += c[x][u];
		u = par[x][u];
		s &= ~(1 << x);
	}
	return {u, ret};
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	d.resize(N + 1);
	par.assign(17, vector<int>(N + 1));
	c.assign(17, vector<ll>(N + 1));
	dfs(1);
	for (int i = 1; i < 17; ++i) {
		for (int j = 1; j <= N; ++j) {
			par[i][j] = par[i - 1][par[i - 1][j]];
			c[i][j] = c[i - 1][j] + c[i - 1][par[i - 1][j]];
		}
	}
	int M{};
	cin >> M;
	while (M--) {
		int q{}, u{}, v{}, k{};
		cin >> q >> u >> v;
		int l = lca(u, v);
		ll ans{};
		if (q == 1) {
			ans = solve(u, d[u] - d[l]).second + solve(v, d[v] - d[l]).second;
		} else {
			cin >> k;
			if (k > d[u] - d[l]) {
				k = d[u] + d[v] - 2 * d[l] - k + 2;
				swap(u, v);
			}
			ans = solve(u, k - 1).first;
		}
		cout << ans << "\n";
	}
	return 0;
}
