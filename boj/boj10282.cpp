#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{}, x{};
		cin >> N >> M >> x;
		vector<vector<ii>> G(N + 1);
		while (M--) {
			int u{}, v{}, w{};
			cin >> v >> u >> w;
			G[u].push_back({v, w});
		}
		vector<int> D(N + 1, INF);
		priority_queue<ii, vector<ii>, greater<ii>> pq;
		pq.push({D[x] = 0, x});
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
		int cnt{}, maxv{};
		for (int i = 1; i <= N; ++i) {
			if (D[i] < INF) {
				++cnt;
				maxv = max(maxv, D[i]);
			}
		}
		cout << cnt << " " << maxv << "\n";
	}
	return 0;
}
