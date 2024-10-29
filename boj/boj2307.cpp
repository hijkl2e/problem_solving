#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int N, M;
vector<vector<ii>> G;

vector<int> dijkstra(int a, int b) {
	static vector<int> D, par;
	D.assign(N + 1, INF);
	par.assign(N + 1, -1);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({D[1] = 0, 1});
	while (pq.size()) {
		auto [d, u] = pq.top(); pq.pop();
		if (D[u] < d) {
			continue;
		}
		for (auto &[v, w] : G[u]) {
			if ((u == a && v == b) || (u == b && v == a)) {
				continue;
			}
			if (D[v] > D[u] + w) {
				pq.push({D[v] = D[u] + w, v});
				par[v] = u;
			}
		}
	}
	vector<int> ret{D[N]};
	if (a != -1) {
		return ret;
	}
	int u = N;
	while (u > 1) {
		ret.push_back(u);
		u = par[u];
	}
	ret.push_back(1);
	return ret;
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
	vector<int> A = dijkstra(-1, -1);
	int maxv{};
	for (int i = 2; i < A.size(); ++i) {
		maxv = max(maxv, dijkstra(A[i - 1], A[i])[0]);
	}
	int ans = maxv == INF ? -1 : (maxv - A[0]);
	cout << ans << "\n";
	return 0;
}
