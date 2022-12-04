#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T = ll>
class FT {
public:
	FT(int n) : ft(n + 1) { }
	FT(vector<T> &A) : ft(A.size()) {
		for (int i = 1; i < ft.size(); ++i) {
			ft[i] += A[i];
			if (i + LSOne(i) < ft.size()) {
				ft[i + LSOne(i)] += ft[i];
			}
		}
	}
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

vector<vector<int>> G;
vector<int> sz, dep, par, top, in, out;

void dfs1(int u) {
	sz[u] = 1;
	for (auto &v : G[u]) {
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
		in[v] = out[v] = out[u] + 1;
		top[v] = v == G[u][0] ? top[u] : v;
		dfs2(v);
		out[u] = out[v];
	}
}

bool solve(FT<int> &ft, int u, int v) {
	int dist = dep[u] + dep[v];
	int res{};
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) {
			swap(u, v);
		}
		res += ft.rsq(in[top[v]], in[v]);
		v = par[top[v]];
	}
	if (dep[u] > dep[v]) {
		swap(u, v);
	}
	res += ft.rsq(in[u] + 1, in[v]);
	dist -= 2 * dep[u];
	return res == dist;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	G.resize(N + 1);
	for (int i = 2; i <= N; ++i) {
		int x{};
		cin >> x;
		G[x].push_back(i);
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
	vector<int> A(N + 1, 1);
	FT<int> ft(A);
	while (Q--) {
		int q{}, a{}, b{};
		cin >> a >> b >> q;
		bool res = solve(ft, a, b);
		cout << (res ? "YES" : "NO") << "\n";
		if (q == 1) {
			if (res) {
				ft.update(in[a], -A[a]);
				A[a] = 0;
			} else {
				ft.update(in[b], -A[b]);
				A[b] = 0;
			}
		}
	}
	return 0;
}
