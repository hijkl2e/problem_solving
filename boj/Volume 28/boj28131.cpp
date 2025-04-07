#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	int s{}, t{};
	cin >> s >> t;
	--s, --t;
	s *= K, t *= K;
	vector<vector<ii>> G(N);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		--u, --v;
		G[u].push_back({v, w});
	}
	vector<int> D(K * N, INF);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({D[s] = 0, s});
	while (pq.size()) {
		auto [d, u] = pq.top(); pq.pop();
		if (D[u] < d) {
			continue;
		}
		int x = u / K, y = u % K;
		for (auto &[v, w] : G[x]) {
			int z = v * K + (y + w) % K;
			if (D[z] > D[u] + w) {
				pq.push({D[z] = D[u] + w, z});
			}
		}
	}
	if (D[t] == INF) {
		cout << "IMPOSSIBLE\n";
	} else {
		cout << D[t] << "\n";
	}
	return 0;
}
