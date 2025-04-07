#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<vector<int>> G;
vector<int> sz, dep, par, top, in, out, rev;
vector<ll> wt;

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
	for (auto &v : G[u]) {
		if (par[u] == v) {
			continue;
		}
		in[v] = out[v] = out[u] + 1;
		top[v] = v == G[u][0] ? top[u] : v;
		dfs2(v);
		out[u] = out[v];
	}
}

ll solve(int u, int v) {
	ll ret{};
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) {
			swap(u, v);
		}
		ret += wt[in[v]] - wt[in[top[v]] - 1];
		v = par[top[v]];
	}
	if (dep[u] > dep[v]) {
		swap(u, v);
	}
	ret += wt[in[v]] - wt[in[u]];
	return ret;
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

int solve(int u, int v, int k) {
	int l = lca(u, v);
	if (dep[u] - dep[l] < k) {
		k = dep[u] + dep[v] - 2 * dep[l] - k;
		u = v;
	}
	while (k >= dep[u] - dep[top[u]] + 1) {
		k -= dep[u] - dep[top[u]] + 1;
		u = par[top[u]];
	}
	return rev[in[u] - k];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N + 1);
	vector<int> u(N);
	vector<int> v(N);
	vector<int> w(N);
	for (int i = 1; i < N; ++i) {
		cin >> u[i] >> v[i] >> w[i];
		G[u[i]].push_back(v[i]);
		G[v[i]].push_back(u[i]);
	}
	sz.resize(N + 1);
	dep.resize(N + 1);
	par.resize(N + 1);
	top.resize(N + 1);
	in.resize(N + 1);
	out.resize(N + 1);
	par[1] = -1;
	top[1] = 1;
	in[1] = out[1] = 1;
	dfs1(1);
	dfs2(1);
	rev.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		rev[in[i]] = i;
	}
	wt.resize(N + 1);
	for (int i = 1; i < N; ++i) {
		if (dep[u[i]] > dep[v[i]]) {
			swap(u[i], v[i]);
		}
		wt[in[v[i]]] = w[i];
	}
	partial_sum(wt.begin(), wt.end(), wt.begin());
	int M{};
	cin >> M;
	while (M--) {
		int q{}, a{}, b{}, c{};
		cin >> q >> a >> b;
		if (q == 1) {
			cout << solve(a, b) << "\n";
		} else {
			cin >> c;
			cout << solve(a, b, c - 1) << "\n";
		}
	}
	return 0;
}
