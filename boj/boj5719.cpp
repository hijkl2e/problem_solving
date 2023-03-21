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
	int N{}, M{};
	while (cin >> N >> M, N) {
		vector<vector<ii>> G(N);
		vector<vector<ii>> H(N);
		int S{}, D{};
		cin >> S >> D;
		while (M--) {
			int u{}, v{}, w{};
			cin >> u >> v >> w;
			G[u].push_back({v, w});
			H[v].push_back({u, w});
		}
		vector<int> d1 = dijkstra(G, S);
		vector<int> d2 = dijkstra(H, D);
		H.assign(N, {});
		for (int u = 0; u < N; ++u) {
			for (auto &[v, w] : G[u]) {
				if (d1[u] + w + d2[v] > d1[D]) {
					H[u].push_back({v, w});
				}
			}
		}
		vector<int> d3 = dijkstra(H, S);
		cout << (d3[D] == INF ? -1 : d3[D]) << "\n";
	}
	return 0;
}
