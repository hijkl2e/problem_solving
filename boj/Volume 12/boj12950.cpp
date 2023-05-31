#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
using ic = pair<int, char>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<ic>> G(N);
	while (M--) {
		int u{}, v{};
		char c{};
		cin >> u >> v >> c;
		G[u].push_back({v, c});
		G[v].push_back({u, c});
	}
	vector<vector<int>> D(N, vector<int>(N, -1));
	queue<ii> q;
	for (int u = 0; u < N; ++u) {
		D[u][u] = 0;
		q.push({u, u});
	}
	for (int u = 0; u < N; ++u) {
		for (auto &[v, c] : G[u]) {
			D[u][v] = 1;
			q.push({u, v});
		}
	}
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (auto &[u, c1] : G[x]) {
			for (auto &[v, c2] : G[y]) {
				if (c1 == c2 && D[u][v] == -1) {
					D[u][v] = D[x][y] + 2;
					q.push({u, v});
				}
			}
		}
	}
	cout << D[0][1] << "\n";
	return 0;
}
