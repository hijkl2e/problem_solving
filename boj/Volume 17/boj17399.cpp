#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G, par;
vector<int> d;

void dfs(int x) {
	for (int y : G[x]) {
		if (y == par[0][x]) {
			continue;
		}
		d[y] = d[x] + 1;
		par[0][y] = x;
		dfs(y);
	}
}

int lca(int u, int v) {
	if (d[u] < d[v]) {
		swap(u, v);
	}
	while (d[u] - d[v]) {
		int x = 31 - __builtin_clz(d[u] - d[v]);
		u = par[x][u];
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

int dist(int u, int v) {
	int l = lca(u, v);
	return d[u] + d[v] - 2 * d[l];
}

int mid(int u, int v) {
	if (d[u] < d[v]) {
		swap(u, v);
	}
	int x = dist(u, v) / 2;
	while (x) {
		int y = 31 - __builtin_clz(x);
		u = par[y][u];
		x &= ~(1 << y);
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
	par.assign(17, vector<int>(N + 1));
	d.resize(N + 1);
	dfs(1);
	for (int i = 1; i < 17; ++i) {
		for (int j = 1; j <= N; ++j) {
			par[i][j] = par[i - 1][par[i - 1][j]];
		}
	}
	int Q{};
	cin >> Q;
	while (Q--) {
		int a{}, b{}, c{};
		cin >> a >> b >> c;
		int r = d[a] % 2 + d[b] % 2 + d[c] % 2;
		if (r == 1 || r == 2) {
			cout << "-1\n";
			continue;
		}
		int x = mid(a, b);
		int y = mid(b, c);
		int z = mid(c, a);
		int ans = x == y ? x : y == z ? y : z == x ? z : -1;
		cout << ans << "\n";
	}
	return 0;
}
