#include <bits/stdc++.h>

using namespace std;

using edge = tuple<int, int, int>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> D(N + 1, vector<int>(N + 1, INF));
	for (int i = 1; i <= N; ++i) {
		D[i][i] = 0;
	}
	vector<edge> E(M);
	for (auto &[u, v, w] : E) {
		cin >> u >> v >> w;
		w *= 2;
		D[u][v] = min(D[u][v], w);
		D[v][u] = min(D[v][u], w);
	}
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	int ans = INF;
	for (int i = 1; i <= N; ++i) {
		int maxv{};
		for (auto &[u, v, w] : E) {
			maxv = max(maxv, (D[i][u] + D[i][v] + w) / 2);
		}
		ans = min(ans, maxv);
	}
	cout << ans / 2 << "." << (ans % 2 ? 5 : 0) << "\n";
	return 0;
}
