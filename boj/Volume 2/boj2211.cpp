#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int N, M;
vector<vector<ii>> G;

vector<int> dijkstra(int s) {
	vector<int> D(N + 1, INF);
	vector<int> par(N + 1, -1);
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
				par[v] = u;
			}
		}
	}
	return par;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	G.resize(N + 1);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	vector<int> par = dijkstra(1);
	cout << N - 1 << "\n";
	for (int i = 2; i <= N; ++i) {
		cout << i << " " << par[i] << "\n";
	}
	return 0;
}
