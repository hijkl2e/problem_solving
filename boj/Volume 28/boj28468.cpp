#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<deque<bool>> A(N + 1, deque<bool>(N + 1));
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		A[u][v] = A[v][u] = true;
	}
	vector<ll> B(N + 1);
	vector<vector<int>> C(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			for (int k = j + 1; k <= N; ++k) {
				if (A[i][j] && A[j][k] && A[k][i]) {
					++B[i], ++B[j], ++B[k];
					++C[i][j], ++C[j][k], ++C[k][i];
					++C[j][i], ++C[k][j], ++C[i][k];
				}
			}
		}
	}
	ll ans{};
	for (int i = 1; i <= N; ++i) {
		int x = accumulate(A[i].begin(), A[i].end(), 0) - 4;
		if (x < 2 || B[i] < 2) {
			continue;
		}
		ll y = B[i] * (B[i] - 1);
		for (int j = 1; j <= N; ++j) {
			y -= C[i][j] * (C[i][j] - 1);
		}
		ans += y * x * (x - 1) / 4;
	}
	cout << ans << "\n";
	return 0;
}
