#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using iii = tuple<ll, int, int>;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<vector<ii>> G(N + 1);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	vector<vector<ll>> D(N + 1, vector<ll>(K + 1, INF));
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	pq.push({D[1][0] = 0, 1, 0});
	while (pq.size()) {
		auto [d, u, k] = pq.top(); pq.pop();
		if (D[u][k] < d) {
			continue;
		}
		for (auto &[v, w] : G[u]) {
			if (D[v][k] > D[u][k] + w) {
				pq.push({D[v][k] = D[u][k] + w, v, k});
			}
			if (k + 1 <= K && D[v][k + 1] > D[u][k]) {
				pq.push({D[v][k + 1] = D[u][k], v, k + 1});
			}
		}
	}
	ll ans = INF;
	for (int i = 0; i <= K; ++i) {
		ans = min(ans, D[N][i]);
	}
	cout << ans << "\n";
	return 0;
}
