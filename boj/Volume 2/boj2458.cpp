#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(N + 1, vector<int>(N + 1, INF));
	vector<vector<int>> B(N + 1, vector<int>(N + 1, INF));
	for (int i = 1; i <= N; ++i) {
		A[i][i] = B[i][i] = 0;
	}
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		A[u][v] = B[v][u] = 1;
	}
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
				B[i][j] = min(B[i][j], B[i][k] + B[k][j]);
			}
		}
	}
	int ans{};
	for (int i = 1; i <= N; ++i) {
		int cnt = count(A[i].begin(), A[i].end(), INF) + count(B[i].begin(), B[i].end(), INF);
		if (cnt == N + 1) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
