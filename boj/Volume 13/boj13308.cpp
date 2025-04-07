#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using iii = tuple<ll, int, int>;

const ll INF = 4e18;

int N;
vector<vector<ii>> G;
vector<int> A;

ll dijkstra(int s, int t) {
	vector<vector<ll>> D(N + 1, vector<ll>(N + 1, INF));
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	pq.push({D[s][s] = 0, s, s});
	while (pq.size()) {
		auto [d, u, x] = pq.top(); pq.pop();
		if (D[u][x] < d) {
			continue;
		} else if (u == t) {
			return d;
		}
		for (auto &[v, w] : G[u]) {
			int y = A[v] < A[x] ? v : x;
			if (D[v][y] > D[u][x] + w * A[x]) {
				pq.push({D[v][y] = D[u][x] + w * A[x], v, y});
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{};
	cin >> N >> M;
	A.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	G.resize(N + 1);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	cout << dijkstra(1, N) << "\n";
	return 0;
}
