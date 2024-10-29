#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<vector<iii>> G(N + 1);
	while (K--) {
		int u{}, v{}, c{}, d{};
		cin >> u >> v >> c >> d;
		G[u].push_back({v, c, d});
	}
	vector<vector<int>> D(N + 1, vector<int>(M + 1, INF));
	D[1][0] = 0;
	for (int j = 0; j < M; ++j) {
		for (int i = 1; i <= N; ++i) {
			if (D[i][j] == INF) {
				continue;
			}
			for (auto &[v, c, d] : G[i]) {
				if (j + c <= M) {
					D[v][j + c] = min(D[v][j + c], D[i][j] + d);
				}
			}
		}
	}
	int minv = *min_element(D[N].begin(), D[N].end());
	if (minv == INF) {
		cout << "Poor KCM\n";
	} else {
		cout << minv << "\n";
	}
	return 0;
}
