#include <bits/stdc++.h>

using namespace std;

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
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		D[u][v] = D[v][u] = w;
	}
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	vector<vector<int>> B(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i == j) {
				continue;
			}
			B[i][j] = j;
			for (int k = 1; k <= N; ++k) {
				if (i == k) {
					continue;
				}
				if (D[i][j] == D[i][k] + D[k][j] && D[i][B[i][j]] > D[i][k]) {
					B[i][j] = k;
				}
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i == j) {
				cout << "-";
			} else {
				cout << B[i][j];
			}
			cout << (j == N ? "\n" : " ");
		}
	}
	return 0;
}
