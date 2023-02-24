#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

const ll INF = 1e18;

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
	vector<vector<ll>> D(P);
	for (int i = 0; i < P; ++i) {
		D[i] = dijkstra(Y[i]);
	}
	ll ans = INF;
	for (int i = 0; i < P; ++i) {
		for (int j = 0; j < P; ++j) {
			if (i == j) {
				continue;
			}
			for (int k = 0; k < P; ++k) {
				if (i == k || j == k) {
					continue;
				}
				ans = min(ans, D[i][X] + D[i][Y[j]] + D[k][Y[j]] + D[k][Z]);
			}
		}
	}
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
