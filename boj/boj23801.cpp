#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

const ll INF = 4e18;

int N;
vector<vector<ii>> G;

vector<ll> dijkstra(int s) {
	vector<ll> D(N + 1, INF);
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
	int X{}, Z{}, P{};
	cin >> X >> Z >> P;
	vector<int> Y(P);
	for (int i = 0; i < P; ++i) {
		cin >> Y[i];
	}
	vector<ll> d1 = dijkstra(X);
	vector<ll> d2 = dijkstra(Z);
	ll ans = INF;
	for (int y : Y) {
		ans = min(ans, d1[y] + d2[y]);
	}
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
