#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using edge = tuple<ll, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<ii>> G(N + 1);
	vector<edge> E(M);
	for (auto &[w, u, v] : E) {
		cin >> u >> v >> w;
		G[u].push_back({w, v});
		G[v].push_back({w, u});
	}
	for (int i = 1; i <= N; ++i) {
		sort(G[i].rbegin(), G[i].rend());
	}
	sort(E.rbegin(), E.rend());
	ll ans{};
	for (int i = 0; i < 2 && i < M; ++i) {
		ans += get<0>(E[i]);
	}
	for (auto &[w, u, v] : E) {
		if (G[u].size() == 1 || G[v].size() == 1) {
			continue;
		}
		int x = G[u][0].second == v;
		int y = G[v][0].second == u;
		if (G[u][x].second == G[v][y].second) {
			int nx = x + 1, ny = y + 1;
			if (nx < G[u].size() && G[u][nx].second == v) {
				++nx;
			}
			if (ny < G[v].size() && G[v][ny].second == u) {
				++ny;
			}
			if (nx < G[u].size()) {
				ans = max(ans, w + G[u][nx].first + G[v][y].first);
			}
			if (ny < G[v].size()) {
				ans = max(ans, w + G[u][x].first + G[v][ny].first);
			}
		} else {
			ans = max(ans, w + G[u][x].first + G[v][y].first);
		}
	}
	cout << ans << "\n";
	return 0;
}
