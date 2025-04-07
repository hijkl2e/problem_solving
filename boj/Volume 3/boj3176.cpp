#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const int INF = 1e9 + 7;

template <typename T = ll>
class Seg {
public:
	Seg(int sz) : n(sz), st(2 * sz) { }
	Seg(vector<T> &A) : n(A.size()), st(2 * A.size()) {
		copy(A.begin(), A.end(), st.begin() + n);
		for (int i = n - 1; i > 0; --i) {
			st[i] = min(st[2 * i], st[2 * i + 1]);
		}
	}
	void update(int p, T val) {
		for (st[p += n] = val; p > 1; p /= 2) {
			st[p / 2] = min(st[p], st[p ^ 1]);
		}
	}
	T rmq(int l, int r) {
		T ret = INF;
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) {
				ret = min(ret, st[l++]);
			}
			if (r & 1) {
				ret = min(st[--r], ret);
			}
		}
		return ret;
	}
private:
	int n;
	vector<T> st;
};

vector<vector<ii>> G;
vector<int> sz, dep, par, top, dist, in, out;

void dfs1(int u) {
	sz[u] = 1;
	for (auto &p : G[u]) {
		auto &[v, w] = p;
		if (par[u] == v) {
			continue;
		}
		dep[v] = dep[u] + 1;
		par[v] = u;
		dfs1(v);
		sz[u] += sz[v];
		if (sz[v] > sz[G[u][0].first]) {
			swap(p, G[u][0]);
		}
	}
}

void dfs2(int u) {
	for (auto &[v, w] : G[u]) {
		if (par[u] == v) {
			continue;
		}
		in[v] = out[v] = out[u] + 1;
		top[v] = v == G[u][0].first ? top[u] : v;
		dist[in[v]] = w;
		dfs2(v);
		out[u] = out[v];
	}
}

int solve(Seg<int> &seg, int u, int v) {
	int ret = INF;
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) {
			swap(u, v);
		}
		int tv = top[v];
		ret = min(ret, seg.rmq(in[tv], in[v] + 1));
		v = par[top[v]];
	}
	if (dep[u] > dep[v]) {
		swap(u, v);
	}
	ret = min(ret, seg.rmq(in[u] + 1, in[v] + 1));
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	sz.resize(N + 1);
	dep.resize(N + 1);
	par.resize(N + 1);
	top.resize(N + 1);
	dist.resize(N + 1);
	in.resize(N + 1);
	out.resize(N + 1);
	par[1] = -1;
	top[1] = 1;
	dfs1(1);
	dfs2(1);
	vector<int> rdist(N + 1);
	for (int i = 0; i < N; ++i) {
		rdist[i] = -dist[i];
	}
	Seg seg1(dist);
	Seg seg2(rdist);
	int M{};
	cin >> M;
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		cout << solve(seg1, u, v) << " " << -solve(seg2, u, v) << "\n";
	}
	return 0;
}
