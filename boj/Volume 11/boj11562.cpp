#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> D(N + 1, vector<int>(N + 1, INF));
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		D[u][v] = 0;
		D[v][u] = w ? 0 : 1;
	}
	for (int i = 1; i <= N; ++i) {
		D[i][i] = 0;
	}
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	int K{};
	cin >> K;
	while (K--) {
		int s{}, e{};
		cin >> s >> e;
		cout << D[s][e] << "\n";
	}
	return 0;
}
