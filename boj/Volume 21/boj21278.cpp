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
		int u{}, v{};
		cin >> u >> v;
		D[u][v] = D[v][u] = 1;
	}
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	int ans_x{}, ans_y{}, ans_d = INF;
	for (int i = 1; i <= N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			int sum{};
			for (int k = 1; k <= N; ++k) {
				sum += 2 * min(D[k][i], D[k][j]);
			}
			if (ans_d > sum) {
				ans_d = sum;
				ans_x = i;
				ans_y = j;
			}
		}
	}
	cout << ans_x << " " << ans_y << " " << ans_d << "\n";
	return 0;
}
