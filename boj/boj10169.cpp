#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using edge = tuple<int, int, int, int>;

const int INF = 1e9 + 7;

class UF {
public:
	UF() { }
	UF(int N) : par(N), sz(N, 1), nxt(N) {
		for (int i = 0; i < N; ++i) {
			par[i] = nxt[i] = i;
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
		int n = nxt[x];
		if (sz[x] < sz[y]) {
			swap(x, y);
		}
		par[y] = x;
		sz[x] += sz[y];
		nxt[x] = n;
		return true;
	}
	int size(int x) {
		return sz[root(x)];
	}
	int next(int x) {
		return nxt[root(x)];
	}
private:
	vector<int> par, sz, nxt;
};

vector<vector<int>> G;
vector<int> d;
vector<vector<int>> par, minv;
UF uf;

void dfs(int u) {
	for (int v : G[u]) {
		if (par[0][u] == v) {
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

void solve(int u, int l, int w) {
	u = uf.next(u);
	while (d[u] - d[l] > 0) {
		minv[0][u] = w;
		uf.unite(par[0][u], u);
		u = uf.next(u);
	}
}

int solve(int u, int s) {
	int ret = INF;
	while (s) {
		int x = __builtin_ctz(s);
		ret = min(ret, minv[x][u]);
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
	for (int i = 0; i < M; ++i) {
		auto &[w, u, v, idx] = E[i];
		cin >> u >> v >> w;
		idx = i;
	}
	sort(E.begin(), E.end());
	uf = UF(N + 1);
	G.resize(N + 1);
	deque<bool> A(M);
	ll sum{};
	for (auto &[w, u, v, idx] : E) {
		if (uf.unite(u, v)) {
			G[u].push_back(v);
			G[v].push_back(u);
			A[idx] = true;
			sum += w;
		}
	}
	d.resize(N + 1);
	par.assign(17, vector<int>(N + 1));
	dfs(1);
	for (int i = 1; i < 17; ++i) {
		for (int j = 1; j <= N; ++j) {
			par[i][j] = par[i - 1][par[i - 1][j]];
		}
	}
	minv.resize(17, vector<int>(N + 1, INF));
	uf = UF(N + 1);
	for (auto &[w, u, v, idx] : E) {
		if (A[idx]) {
			continue;
		}
		int l = lca(u, v);
		solve(u, l, w);
		solve(v, l, w);
	}
	for (int i = 1; i < 17; ++i) {
		for (int j = 1; j <= N; ++j) {
			minv[i][j] = min(minv[i - 1][j], minv[i - 1][par[i - 1][j]]);
		}
	}
	vector<ll> C(M);
	for (auto &[w, u, v, idx] : E) {
		if (A[idx]) {
			int l = lca(u, v);
			int res = min(solve(u, d[u] - d[l]), solve(v, d[v] - d[l]));
			C[idx] = res == INF ? -1 : (sum + res - w);
		} else {
			C[idx] = sum;
		}
	}
	for (ll x : C) {
		cout << x << "\n";
	}
	return 0;
}
