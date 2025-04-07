#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int N;
vector<vector<ii>> G;
vector<ll> sz;
ll minv, maxv;

ll dfs1(int u, int p) {
	ll ret{};
	for (auto &[v, w] : G[u]) {
		if (v == p) {
			continue;
		}
		ret += dfs1(v, u);
		ret += sz[v] * w;
		sz[u] += sz[v];
	}
	return ret;
}

void dfs2(int u, int p, ll val) {
	minv = min(minv, val);
	maxv = max(maxv, val);
	for (auto &[v, w] : G[u]) {
		if (v == p) {
			continue;
		}
		dfs2(v, u, val + (N - 2 * sz[v]) * w);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	sz.assign(N + 1, 1);
	minv = maxv = dfs1(1, -1);
	dfs2(1, -1, minv);
	cout << minv << " " << maxv << "\n";
	return 0;
}
