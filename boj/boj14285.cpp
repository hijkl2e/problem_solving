#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
using edge = tuple<int, int, int>;

const int INF = 1e9 + 7;

int N, M;
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
	cin >> N >> M;
	G.resize(N + 1);
	vector<edge> E(M);
	int sum{};
	for (auto &[u, v, w] : E) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
		sum += w;
	}
	int s{}, t{};
	cin >> s >> t;
	vector<int> d1 = dijkstra(s);
	vector<int> d2 = dijkstra(t);
	int ans{};
	for (auto &[u, v, w] : E) {
		ans = max(ans, sum - d1[u] - d2[v]);
		ans = max(ans, sum - d1[v] - d2[u]);
	}
	cout << ans << "\n";
	return 0;
}
