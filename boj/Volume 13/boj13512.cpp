#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T = ll>
class Seg {
public:
	Seg(int sz) : n(sz), st(2 * sz) { }
	void update(int p) {
		for (st[p + n] ^= p, p = (p + n) / 2; p > 0; p /= 2) {
			st[p] = conquer(st[2 * p], st[2 * p + 1]);
		}
	}
	int rmq(int l, int r) {
		int L{}, R{};
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) {
				L = conquer(L, st[l++]);
			}
			if (r & 1) {
				R = conquer(st[--r], R);
			}
		}
		return conquer(L, R);
	}
private:
	int conquer(int a, int b) {
		return a ? a : b;
	}
	int n;
	vector<T> st, A;
};

vector<vector<int>> G;
vector<int> sz, dep, par, top, in, out, rev;

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

int solve(Seg<int> &seg, int v) {
	int ret = -1;
	while (v != -1) {
		int res = seg.rmq(in[top[v]], in[v] + 1);
		ret = res ? rev[res] : ret;
		v = par[top[v]];
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
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
	in[1] = out[1] = 1;
	dfs1(1);
	dfs2(1);
	rev.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		rev[in[i]] = i;
	}
	Seg<int> seg(N + 1);
	int M{};
	cin >> M;
	while (M--) {
		int q{}, a{};
		cin >> q >> a;
		if (q == 1) {
			seg.update(in[a]);
		} else {
			cout << solve(seg, a) << "\n";
		}
	}
	return 0;
}
