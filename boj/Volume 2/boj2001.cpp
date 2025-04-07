#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	deque<bool> A(N + 1);
	for (int i = 0; i < K; ++i) {
		int x{};
		cin >> x;
		A[x] = true;
	}
	vector<int> B(N + 1);
	for (int i = 1; i <= N; ++i) {
		B[i] = B[i - 1] + A[i - 1];
	}
	vector<vector<ii>> G(N + 1);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	vector<deque<bool>> D(N + 1, deque<bool>(1 << K));
	queue<ii> q;
	D[1][0] = true;
	q.push({1, 0});
	while (q.size()) {
		auto [u, b] = q.front(); q.pop();
		if (A[u]) {
			int nb = (b | (1 << B[u]));
			if (!D[u][nb]) {
				D[u][nb] = true;
				q.push({u, nb});
			}
		}
		int cnt = __builtin_popcount(b);
		for (auto &[v, w] : G[u]) {
			if (cnt <= w && !D[v][b]) {
				D[v][b] = true;
				q.push({v, b});
			}
		}
	}
	int ans{};
	for (int i = 0; i < (1 << K); ++i) {
		if (D[1][i]) {
			ans = max(ans, __builtin_popcount(i));
		}
	}
	cout << ans << "\n";
	return 0;
}
