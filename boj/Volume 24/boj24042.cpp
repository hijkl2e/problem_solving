#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<ii>> G(N + 1);
	for (int i = 0; i < M; ++i) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back({v, i});
		G[v].push_back({u, i});
	}
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	vector<ll> D(N + 1, INF);
	pq.push({D[1] = 0, 1});
	while (pq.size()) {
		auto [d, u] = pq.top(); pq.pop();
		if (D[u] < d) {
			continue;
		}
		ll T = D[u] % M;
		for (auto &[v, w] : G[u]) {
			ll t = D[u] - T + w + M * (T > w) + 1;
			if (D[v] > t) {
				pq.push({D[v] = t, v});
			}
		}
	}
	cout << D[N] << "\n";
	return 0;
}
