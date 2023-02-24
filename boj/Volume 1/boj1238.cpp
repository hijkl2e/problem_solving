#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

vector<int> dijkstra(vector<vector<ii>> &G, int s) {
	vector<int> D(G.size(), INF);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({D[s] = 0, s});
	while (pq.size()) {
		auto [d, u] = pq.top(); pq.pop();
		if (D[u] < d) {
			continue;
		}
		for (auto &[v, w] : G[u]) {
			if (D[v] > D[u] + w) {
				pq.push({D[v] = D[u] + w, v});
			}
		}
	}
	return D;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, X{};
	cin >> N >> M >> X;
	vector<vector<ii>> G(N + 1);
	vector<vector<ii>> H(N + 1);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		H[v].push_back({u, w});
	}
	vector<int> d1 = dijkstra(G, X);
	vector<int> d2 = dijkstra(H, X);
	int ans{};
	for (int i = 1; i <= N; ++i) {
		ans = max(ans, d1[i] + d2[i]);
	}
	cout << ans << "\n";
	return 0;
}
