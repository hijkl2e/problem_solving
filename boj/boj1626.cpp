#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;

const ll INF = 4e18;

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
vector<vector<int>> par, maxv1, maxv2;

void dfs(int u) {
	for (auto &[v, w] : G[u]) {
		if (par[0][u] == v) {
			continue;
		}
		d[v] = d[u] + 1;
		par[0][v] = u;
		maxv1[0][v] = w;
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
	for (int i = 15; i >= 0; --i) {
		if (par[i][u] != par[i][v]) {
			u = par[i][u];
			v = par[i][v];
		}
	}
	return par[0][u];
}

ii solve(int u, int s) {
	vector<int> A(4, -1);
	while (s) {
		int x = __builtin_ctz(s);
		A.resize(4, -1);
		A[2] = maxv1[x][u];
		A[3] = maxv2[x][u];
		sort(A.rbegin(), A.rend());
		A.resize(unique(A.begin(), A.end()) - A.begin());
		u = par[x][u];
		s &= ~(1 << x);
	}
	return {A[0], A[1]};
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
	ll sum{};
	int cnt{};
	for (auto &[w, u, v] : F) {
		if (uf.unite(u, v)) {
			G[u].push_back({v, w});
			G[v].push_back({u, w});
			sum += w;
			++cnt;
		}
	}
	if (cnt < N - 1) {
		cout << "-1\n";
		return 0;
	}
	d.resize(N + 1);
	par.assign(16, vector<int>(N + 1));
	maxv1.assign(16, vector<int>(N + 1, -1));
	maxv2.assign(16, vector<int>(N + 1, -1));
	dfs(1);
	vector<int> A;
	for (int i = 1; i < 16; ++i) {
		for (int j = 1; j <= N; ++j) {
			par[i][j] = par[i - 1][par[i - 1][j]];
			A = {maxv1[i - 1][j], maxv2[i - 1][j], maxv1[i - 1][par[i - 1][j]], maxv2[i - 1][par[i - 1][j]]};
			sort(A.rbegin(), A.rend());
			A.resize(unique(A.begin(), A.end()) - A.begin());
			maxv1[i][j] = A[0];
			maxv2[i][j] = A[1];
		}
	}
	ll ans = INF;
	for (auto &[w, u, v] : E) {
		int l = lca(u, v);
		A.resize(4);
		tie(A[0], A[1]) = solve(u, d[u] - d[l]);
		tie(A[2], A[3]) = solve(v, d[v] - d[l]);
		sort(A.rbegin(), A.rend());
		A.resize(unique(A.begin(), A.end()) - A.begin());
		ans = min(ans, sum + w - (w == A[0] ? A[1] == -1 ? -INF : A[1] : A[0]));
	}
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
