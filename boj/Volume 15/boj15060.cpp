#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
using edge = tuple<int, int, int>;

class UF {
public:
	UF(int N) : par(N), sz(N, 1) {
		for (int i = 0; i < N; ++i) {
			par[i] = i;
		}
	}
	int root(int x) {
		return par[x] == x ? x : (par[x] = root(par[x]));
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	bool unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) {
			return false;
		}
		if (sz[x] < sz[y]) {
			swap(x, y);
		}
		par[y] = x;
		sz[x] += sz[y];
		return true;
	}
	int size(int x) {
		return sz[root(x)];
	}
private:
	vector<int> par, sz;
};

vector<vector<ii>> G;
vector<int> d;
vector<vector<int>> par, maxv;

void dfs(int u) {
	for (auto &[v, w] : G[u]) {
		if (par[0][u] == v) {
			continue;
		}
		d[v] = d[u] + 1;
		par[0][v] = u;
		maxv[0][v] = w;
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
	int ret{};
	while (s) {
		int x = __builtin_ctz(s);
		ret = max(ret, maxv[x][u]);
		u = par[x][u];
		s &= ~(1 << x);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<edge> E(M);
	for (auto &[w, u, v] : E) {
		cin >> u >> v >> w;
	}
	vector<edge> F(E.begin(), E.end());
	sort(F.begin(), F.end());
	UF uf(N + 1);
	G.resize(N + 1);
	int sum{};
	for (auto &[w, u, v] : F) {
		if (uf.unite(u, v)) {
			G[u].push_back({v, w});
			G[v].push_back({u, w});
			sum += w;
		}
	}
	d.resize(N + 1);
	par.assign(17, vector<int>(N + 1));
	maxv.assign(17, vector<int>(N + 1));
	dfs(1);
	for (int i = 1; i < 17; ++i) {
		for (int j = 1; j <= N; ++j) {
			par[i][j] = par[i - 1][par[i - 1][j]];
			maxv[i][j] = max(maxv[i - 1][j], maxv[i - 1][par[i - 1][j]]);
		}
	}
	for (auto &[w, u, v] : F) {
		tie(w, u, v) = make_tuple(u, v, w);
	}
	sort(F.begin(), F.end());
	int Q{};
	cin >> Q;
	while (Q--) {
		int u{}, v{};
		cin >> u >> v;
		int w = get<2>(*lower_bound(F.begin(), F.end(), make_tuple(u, v, -1)));
		int l = lca(u, v);
		int ans = sum + w - max(solve(u, d[u] - d[l]), solve(v, d[v] - d[l]));
		cout << ans << "\n";
	}
	return 0;
}
