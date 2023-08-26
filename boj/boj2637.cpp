#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<ii>> G(N + 1);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
	}
	vector<int> ind(N + 1);
	for (int u = 1; u <= N; ++u) {
		for (auto &[v, w] : G[u]) {
			++ind[v];
		}
	}
	vector<int> A(N + 1);
	A[N] = 1;
	queue<int> q;
	q.push(N);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (auto &[v, w] : G[u]) {
			A[v] += w * A[u];
			if (--ind[v] == 0) {
				q.push(v);
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (G[i].empty()) {
			cout << i << " " << A[i] << "\n";
		}
	}
	return 0;
}
