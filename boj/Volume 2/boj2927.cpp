#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using query = tuple<int, int, int>;

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
	in[u] = ++cntr;
	for (auto &v : G[u]) {
		if (par[u] == v) {
			continue;
		}
		top[v] = v == G[u][0] ? top[u] : v;
		dfs2(v);
	}
	out[u] = cntr;
}

int solve(FT<int> &ft, int u, int v) {
	int ret{};
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) {
			swap(u, v);
		}
		ret += ft.rsq(in[top[v]], in[v]);
		v = par[top[v]];
	}
	if (dep[u] > dep[v]) {
		swap(u, v);
	}
	ret += ft.rsq(in[u], in[v]);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	int Q{};
	cin >> Q;
	vector<query> B(Q);
	G.resize(N + 1);
	UF uf(N + 1);
	for (int i = 0; i < Q; ++i) {
		auto &[q, a, b] = B[i];
		string cmd;
		cin >> cmd >> a >> b;
		q = cmd == "bridge" ? 0 : cmd == "penguins" ? 1 : 2;
		if (q == 0) {
			if (uf.unite(a, b)) {
				G[a].push_back(b);
				G[b].push_back(a);
			}
		}
	}
	sz.resize(N + 1);
	dep.resize(N + 1);
	par.resize(N + 1);
	top.resize(N + 1);
	in.resize(N + 1);
	out.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		if (sz[i]) {
			continue;
		}
		par[i] = -1;
		top[i] = i;
		dfs1(i);
		dfs2(i);
	}
	vector<int> C(N + 1);
	for (int i = 1; i <= N; ++i) {
		C[in[i]] = A[i];
	}
	FT<int> ft(C);
	uf = UF(N + 1);
	for (auto &[q, a, b] : B) {
		if (q == 0) {
			cout << (uf.unite(a, b) ? "yes" : "no") << "\n";
		} else if (q == 1) {
			a = in[a];
			ft.update(a, b - C[a]);
			C[a] = b;
		} else {
			if (uf.same(a, b)) {
				cout << solve(ft, a, b) << "\n";
			} else {
				cout << "impossible\n";
			}
		}
	}
	return 0;
}
