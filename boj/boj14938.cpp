#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, R{};
	cin >> N >> M >> R;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<vector<int>> D(N + 1, vector<int>(N + 1, INF));
	for (int i = 1; i <= N; ++i) {
		D[i][i] = 0;
	}
	while (R--) {
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
	int ans{};
	for (int i = 1; i <= N; ++i) {
		int cnt{};
		for (int j = 1; j <= N; ++j) {
			if (D[i][j] <= M) {
				cnt += A[j];
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
	return 0;
}
