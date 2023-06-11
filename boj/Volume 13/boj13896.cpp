#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G, par;
vector<int> d, sz;

void dfs(int x) {
	for (int y : G[x]) {
		if (y == par[0][x]) {
			continue;
		}
		d[y] = d[x] + 1;
		par[0][y] = x;
		dfs(y);
		sz[x] += sz[y];
	}
}

int solve(int u, int v) {
	if (d[u] == d[v]) {
		return -1;
	} else if (d[u] < d[v]) {
		swap(u, v);
	}
	while (d[u] - d[v] - 1) {
		int x = 31 - __builtin_clz(d[u] - d[v] - 1);
		u = par[x][u];
	}
	if (par[0][u] == v) {
		return u;
	}
	u = par[0][u];
	for (int i = 16; i >= 0; --i) {
		if (par[i][u] != par[i][v]) {
			u = par[i][u];
			v = par[i][v];
		}
	}
	return u;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cout << "Case #" << tc << ":\n";
		int N{}, Q{}, R{};
		cin >> N >> Q >> R;
		G.assign(N + 1, {});
		for (int i = 0; i < N - 1; ++i) {
			int u{}, v{};
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		d.resize(N + 1);
		sz.assign(N + 1, 1);
		par.assign(17, vector<int>(N + 1));
		dfs(1);
		for (int i = 1; i < 17; ++i) {
			for (int j = 1; j <= N; ++j) {
				par[i][j] = par[i - 1][par[i - 1][j]];
			}
		}
		while (Q--) {
			int q{}, u{};
			cin >> q >> u;
			if (q == 0) {
				R = u;
				continue;
			} else if (R == u) {
				cout << N << "\n";
				continue;
			}
			int v = solve(R, u);
			int ans = par[0][v] == u ? N - sz[v] : sz[u];
			cout << ans << "\n";
		}
	}
	return 0;
}
