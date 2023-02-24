#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int N;
vector<vector<ii>> G;

int dijkstra(int s, int g) {
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
	return D[g];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{};
	cin >> N >> M;
	G.resize(N + 1);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
	}
	int A{}, B{};
	cin >> A >> B;
	cout << dijkstra(A, B) << "\n";
	return 0;
}
