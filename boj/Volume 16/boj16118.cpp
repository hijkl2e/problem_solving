#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 2e9 + 7;

vector<int> dijkstra(vector<vector<ii>> &G, int s) {
	int N = G.size();
	vector<int> D(N, INF);
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
	int N{}, M{};
	cin >> N >> M;
	vector<vector<ii>> G(2 * N + 1);
	vector<vector<ii>> H(2 * N + 1);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		w *= 2;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
		H[u].push_back({v + N, w / 2});
		H[v].push_back({u + N, w / 2});
		H[u + N].push_back({v, w * 2});
		H[v + N].push_back({u, w * 2});
	}
	vector<int> d1 = dijkstra(G, 1);
	vector<int> d2 = dijkstra(H, 1);
	int ans{};
	for (int i = 1; i <= N; ++i) {
		if (d1[i] < min(d2[i], d2[i + N])) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
