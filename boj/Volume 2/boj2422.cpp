#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<deque<bool>> A(N + 1, deque<bool>(N + 1, true));
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		A[u][v] = A[v][u] = false;
	}
	int ans{};
	for (int i = 1; i <= N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			for (int k = j + 1; k <= N; ++k) {
				if (A[i][j] && A[j][k] && A[k][i]) {
					++ans;
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
