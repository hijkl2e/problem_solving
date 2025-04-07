#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

vector<vector<ii>> G;
vector<int> d;
vector<ii> par;

void dfs(int u) {
	for (auto &[v, w] : G[u]) {
		if (v == par[u].first) {
			continue;
		}
		d[v] = d[u] + 1;
		par[v] = {u, w};
		dfs(v);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	d.resize(N + 1);
	par.resize(N + 1);
	dfs(1);
	while (M--) {
		int x{}, y{};
		cin >> x >> y;
		if (d[x] < d[y]) {
			swap(x, y);
		}
		int ans{};
		while (d[x] > d[y]) {
			ans += par[x].second;
			x = par[x].first;
		}
		while (x != y) {
			ans += par[x].second + par[y].second;
			x = par[x].first;
			y = par[y].first;
		}
		cout << ans << "\n";
	}
	return 0;
}
