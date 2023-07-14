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
		D[u][v] = 1;
	}
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	int ans{};
	for (int i = 1; i <= N; ++i) {
		int c1 = count(D[i].begin() + 1, D[i].end(), INF);
		int c2{};
		for (int j = 1; j <= N; ++j) {
			if (D[j][i] == INF) {
				++c2;
			}
		}
		if (c1 < N / 2 || c2 < N / 2) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
