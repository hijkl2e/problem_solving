#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	int s{}, g{};
	cin >> s >> g;
	vector<vector<ii>> G(N + 1);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	vector<int> A(K + 1);
	for (int i = 1; i <= K; ++i) {
		cin >> A[i];
	}
	partial_sum(A.begin(), A.end(), A.begin());
	vector<vector<int>> D(N + 1, vector<int>(N + 1, INF));
	D[0][s] = 0;
	for (int i = 0; i < N; ++i) {
		for (int u = 1; u <= N; ++u) {
			if (D[i][u] == INF) {
				continue;
			}
			for (auto &[v, w] : G[u]) {
				D[i + 1][v] = min(D[i + 1][v], D[i][u] + w);
			}
		}
	}
	for (int i = 0; i <= K; ++i) {
		int ans = INF;
		for (int j = 0; j <= N; ++j) {
			ans = min(ans, D[j][g] + j * A[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}
