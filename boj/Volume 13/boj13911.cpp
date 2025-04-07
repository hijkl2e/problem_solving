#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int N, M;
vector<vector<ii>> G;

vector<int> dijkstra(deque<bool> &S) {
	vector<int> D(N + 1, INF);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	for (int i = 1; i <= N; ++i) {
		if (S[i]) {
			pq.push({D[i] = 0, i});
		}
	}
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
	cin >> N >> M;
	G.resize(N + 1);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	int X{};
	cin >> M >> X;
	deque<bool> A(N + 1);
	while (M--) {
		int x{};
		cin >> x;
		A[x] = true;
	}
	int Y{};
	cin >> M >> Y;
	deque<bool> B(N + 1);
	while (M--) {
		int x{};
		cin >> x;
		B[x] = true;
	}
	vector<int> D1 = dijkstra(A);
	vector<int> D2 = dijkstra(B);
	int ans = INF;
	for (int i = 1; i <= N; ++i) {
		if (!A[i] && !B[i] && D1[i] <= X && D2[i] <= Y) {
			ans = min(ans, D1[i] + D2[i]);
		}
	}
	if (ans == INF) {
		ans = -1;
	}
	cout << ans << "\n";
	return 0;
}
