#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> G(N + 1);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= N; ++i) {
		sort(G[i].begin(), G[i].end());
	}
	int ans = INF;
	for (int u = 1; u <= N; ++u) {
		for (int v : G[u]) {
			if (u > v) {
				continue;
			}
			int p1{}, p2{};
			while (p1 < G[u].size() && p2 < G[v].size()) {
				if (G[u][p1] < G[v][p2]) {
					++p1;
				} else if (G[u][p1] > G[v][p2]) {
					++p2;
				} else {
					ans = min<int>(ans, G[u].size() + G[v].size() + G[G[u][p1]].size() - 6);
					++p1, ++p2;
				}
			}
		}
	}
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
