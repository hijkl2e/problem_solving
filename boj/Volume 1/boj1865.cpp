#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{}, W{};
		cin >> N >> M >> W;
		vector<vector<ii>> G(N + 1);
		while (M--) {
			int u{}, v{}, w{};
			cin >> u >> v >> w;
			G[u].push_back({v, w});
			G[v].push_back({u, w});
		}
		while (W--) {
			int u{}, v{}, w{};
			cin >> u >> v >> w;
			G[u].push_back({v, -w});
		}
		vector<int> D(N + 1);
		bool yes{};
		for (int i = 0; i < N; ++i) {
			for (int u = 1; u <= N; ++u) {
				for (auto &[v, w] : G[u]) {
					if (D[v] > D[u] + w) {
						D[v] = D[u] + w;
						if (i == N - 1) {
							yes = true;
						}
					}
				}
			}
		}
		cout << (yes ? "YES" : "NO") << "\n";
	}
	return 0;
}
