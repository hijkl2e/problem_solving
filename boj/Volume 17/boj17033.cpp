#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9 + 7;

template <typename T = ll>
class Seg {
public:
	Seg(int sz) : n(sz), st(2 * sz) { }
	Seg(vector<T> &A) : n(A.size()), st(2 * A.size()) {
		copy(A.begin(), A.end(), st.begin() + n);
		for (int i = n - 1; i > 0; --i) {
			st[i] = st[2 * i] ^ st[2 * i + 1];
		}
	}
	void update(int p, T val) {
		for (st[p += n] = val; p > 1; p /= 2) {
			st[p / 2] = st[p] ^ st[p ^ 1];
		}
	}
	T query(int l, int r) {
		T ret{};
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) {
				ret = ret ^ st[l++];
			}
			if (r & 1) {
				ret = st[--r] ^ ret;
			}
		}
		return ret;
	}
private:
	int n;
	vector<T> st;
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

int solve(Seg<int> &seg, int u, int v) {
	int ret{};
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) {
			swap(u, v);
		}
		ret ^= seg.query(in[top[v]], in[v] + 1);
		v = par[top[v]];
	}
	if (dep[u] > dep[v]) {
		swap(u, v);
	}
	ret ^= seg.query(in[u], in[v] + 1);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	vector<int> e(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> e[i];
	}
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
	vector<int> E(N + 1);
	for (int i = 1; i <= N; ++i) {
		E[in[i]] = e[i];
	}
	Seg seg(E);
	while (Q--) {
		int q{}, a{}, b{};
		cin >> q >> a >> b;
		if (q == 1) {
			seg.update(in[a], b);
		} else {
			cout << solve(seg, a, b) << "\n";
		}
	}
	return 0;
}
