#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

const ll MOD = 1LL << 32;

template <typename T = ll>
class LzSeg {
public:
	LzSeg(int sz) : n(sz), st(4 * sz), lz1(4 * sz, 1), lz2(4 * sz) { }
	void update(int i, int j, T v1, T v2) {
		update(1, 0, n - 1, i, j, v1, v2);
	}
	T rsq(int i, int j) {
		return rsq(1, 0, n - 1, i, j);
	}
private:
	void propagate(int p, int l, int r) {
		T &v1 = lz1[p], &v2 = lz2[p];
		if (v1 == 1 && v2 == 0) {
			return;
		}
		st[p] = (st[p] * v1 % MOD + (r - l + 1) * v2 % MOD) % MOD;
		if (l != r) {
			for (int i = 0; i < 2; ++i) {
				lz1[2 * p + i] = lz1[2 * p + i] * v1 % MOD;
				lz2[2 * p + i] = (lz2[2 * p + i] * v1 % MOD + v2) % MOD;
			}
		}
		v1 = 1, v2 = 0;
	}
	void update(int p, int l, int r, int i, int j, T v1, T v2) {
		propagate(p, l, r);
		if (r < i || j < l) {
			return;
		} else if (i <= l && r <= j) {
			lz1[p] = lz1[p] * v1 % MOD;
			lz2[p] = (lz2[p] * v1 % MOD + v2) % MOD;
			propagate(p, l, r);
			return;
		}
		int m = (l + r) / 2;
		update(2 * p, l, m, i, j, v1, v2);
		update(2 * p + 1, m + 1, r, i, j, v1, v2);
		st[p] = (st[2 * p] + st[2 * p + 1]) % MOD;
	}
	T rsq(int p, int l, int r, int i, int j) {
		propagate(p, l, r);
		if (r < i || j < l) {
			return 0;
		} else if (i <= l && r <= j) {
			return st[p];
		}
		int m = (l + r) / 2;
		return (rsq(2 * p, l, m, i, j) + rsq(2 * p + 1, m + 1, r, i, j)) % MOD;
	}
	int n;
	vector<T> st, lz1, lz2;
};

vector<vector<int>> G;
vector<int> sz, dep, par, top, in, out;

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

ll solve(LzSeg<ll> &seg, int u, int v, int v1, int v2) {
	ll ret{};
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) {
			swap(u, v);
		}
		if (v1 == -1) {
			ret += seg.rsq(in[top[v]], in[v]);
		} else {
			seg.update(in[top[v]], in[v], v1, v2);
		}
		v = par[top[v]];
	}
	if (dep[u] > dep[v]) {
		swap(u, v);
	}
	if (v1 == -1) {
		ret += seg.rsq(in[u], in[v]);
	} else {
		seg.update(in[u], in[v], v1, v2);
	}
	ret %= MOD;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
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
	LzSeg seg(N);
	while (Q--) {
		int q{}, a{}, b{}, c{};
		cin >> q >> a;
		if (q == 5) {
			cout << seg.rsq(in[a], out[a]) << "\n";
			continue;
		}
		cin >> b;
		if (q == 2 || q == 4) {
			cin >> c;
		}
		if (q == 1) {
			seg.update(in[a], out[a], 1, b);
		} else if (q == 3) {
			seg.update(in[a], out[a], b, 0);
		} else if (q == 2) {
			solve(seg, a, b, 1, c);
		} else if (q == 4) {
			solve(seg, a, b, c, 0);
		} else {
			cout << solve(seg, a, b, -1, -1) << "\n";
		}
	}
	return 0;
}
