#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

vector<vector<ii>> G;
vector<int> sz, dep, par, top, dist, in, out, psum;

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

int solve(int u, int v) {
	int ret{};
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) {
			swap(u, v);
		}
		int tv = top[v];
		ret += psum[in[v]] - psum[in[tv] - 1];
		v = par[top[v]];
	}
	if (dep[u] > dep[v]) {
		swap(u, v);
	}
	ret += psum[in[v]] - psum[in[u]];
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
	psum.resize(N + 1);
	par[1] = -1;
	top[1] = 1;
	in[1] = out[1] = 1;
	dfs1(1);
	dfs2(1);
	partial_sum(dist.begin(), dist.end(), psum.begin());
	int M{};
	cin >> M;
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		cout << solve(u, v) << "\n";
	}
	return 0;
}
