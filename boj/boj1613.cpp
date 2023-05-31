#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> D(N, vector<int>(N, INF));
	for (int i = 0; i < N; ++i) {
		D[i][i] = 0;
	}
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		D[u - 1][v - 1] = 1;
	}
	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	int Q{};
	cin >> Q;
	while (Q--) {
		int u{}, v{};
		cin >> u >> v;
		--u, --v;
		cout << (D[u][v] == INF ? D[v][u] == INF ? 0 : 1 : -1) << "\n";
	}
	return 0;
}
