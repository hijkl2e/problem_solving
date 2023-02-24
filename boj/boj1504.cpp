#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e8;

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
	int M{};
	cin >> N >> M;
	G.resize(N + 1);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	int v1{}, v2{};
	cin >> v1 >> v2;
	vector<int> d1 = dijkstra(v1);
	vector<int> d2 = dijkstra(v2);
	int ans = min(d1[1] + d1[v2] + d2[N], d2[1] + d2[v1] + d1[N]);
	cout << (ans < INF ? ans : -1) << "\n";
	return 0;
}
