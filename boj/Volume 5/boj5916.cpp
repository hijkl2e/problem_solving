#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T = ll>
class FT {
public:
	FT() { }
	FT(int n) : ft(n + 1) { }
	T rsq(int i, int j) {
		return rsq(j) - rsq(i - 1);
	}
	T rsq(int j) {
		T res{};
		while (j) {
			res += ft[j];
			j -= LSOne(j);
		}
		return res;
	}
	void update(int i, T v) {
		while (i < ft.size()) {
			ft[i] += v;
			i += LSOne(i);
		}
	}
private:
	T LSOne(T x) {
		return x & -x;
	}
	vector<T> ft;
};

template <typename T = ll>
class RUPQ {
public:
	RUPQ() { }
	RUPQ(int n) : ft(n + 1) { }
	void range_update(int ui, int uj, T v) {
		ft.update(ui, v);
		ft.update(uj + 1, -v);
	}
	T point_query(int i) {
		return ft.rsq(i);
	}
private:
	FT<T> ft;
};

vector<vector<int>> G;
vector<int> sz, dep, par, top, in, out;
int cntr;

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
	in[u] = out[u] = ++cntr;
	for (int v : G[u]) {
		if (par[u] == v) {
			continue;
		}
		top[v] = v == G[u][0] ? top[u] : v;
		dfs2(v);
		out[u] = out[v];
	}
}

RUPQ<ll> ft;

void solve(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) {
			swap(u, v);
		}
		ft.range_update(in[top[v]], in[v], 1);
		v = par[top[v]];
	}
	if (dep[u] > dep[v]) {
		swap(u, v);
	}
	ft.range_update(in[u] + 1, in[v], 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
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
	in.resize(N + 1);
	out.resize(N + 1);
	par[1] = -1;
	top[1] = 1;
	dfs1(1);
	dfs2(1);
	ft = RUPQ(N);
	while (M--) {
		char c{};
		int u{}, v{};
		cin >> c >> u >> v;
		if (dep[u] > dep[v]) {
			swap(u, v);
		}
		if (c == 'P') {
			solve(u, v);
		} else {
			cout << ft.point_query(in[v]) << "\n";
		}
	}
	return 0;
}
