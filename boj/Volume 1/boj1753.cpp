#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int N;
vector<vector<ii>> G;

vector<int> dijkstra(int s) {
	vector<int> D(N + 1, INF);
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
	int M{}, K{};
	cin >> N >> M >> K;
	G.resize(N + 1);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
	}
	vector<int> D = dijkstra(K);
	for (int i = 1; i <= N; ++i) {
		if (D[i] == INF) {
			cout << "INF\n";
		} else {
			cout << D[i] << "\n";
		}
	}
	return 0;
}
