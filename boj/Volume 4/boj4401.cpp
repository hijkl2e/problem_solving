#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int N;
vector<vector<ii>> G;

vector<int> dijkstra(int s) {
	vector<int> D(N + 1, INF);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({D[s] = 0, s});
	while (pq.size()) {
		auto [d, u] = pq.top(); pq.pop();
		if (D[u] < d) {
			continue;
		}
		for (auto &[v, w] : G[u]) {
			if (D[v] > D[u] + w) {
				pq.push({D[v] = D[u] + w, v});
			}
		}
	}
	return D;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int F{};
	cin >> F >> N;
	deque<bool> A(N + 1);
	while (F--) {
		int x{};
		cin >> x;
		A[x] = true;
	}
	G.resize(N + 1);
	int u{}, v{}, w{};
	while (cin >> u >> v >> w) {
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	vector<vector<int>> D(N + 1);
	for (int i = 1; i <= N; ++i) {
		D[i] = dijkstra(i);
	}
	vector<int> B(N + 1, INF);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (A[j]) {
				B[i] = min(B[i], D[i][j]);
			}
		}
	}
	int ans_x = -1, ans_d = INF;
	for (int i = 1; i <= N; ++i) {
		int maxv{};
		for (int j = 1; j <= N; ++j) {
			maxv = max(maxv, min(B[j], D[i][j]));
		}
		if (ans_d > maxv) {
			ans_d = maxv;
			ans_x = i;
		}
	}
	cout << ans_x << "\n";
	return 0;
}
