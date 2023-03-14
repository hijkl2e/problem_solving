#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

const ll INF = 4e18;

vector<ll> dijkstra(vector<vector<ii>> &G, int s) {
	vector<ll> D(G.size(), INF);
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
	int N{}, M{};
	cin >> N >> M;
	vector<vector<ii>> G(N);
	vector<vector<ii>> H(N);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		H[v].push_back({u, w});
	}
	int s{}, t{};
	cin >> s >> t;
	vector<ll> d1 = dijkstra(G, s);
	vector<ll> d2 = dijkstra(H, t);
	H.assign(N, {});
	for (int u = 0; u < N; ++u) {
		for (auto &[v, w] : G[u]) {
			if (d1[u] + w + d2[v] == d1[t]) {
				H[u].push_back({v, w});
			}
		}
	}
	vector<ll> D(N, INF);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({D[s] = 0, s});
	vector<int> A;
	while (pq.size()) {
		auto [d, u] = pq.top(); pq.pop();
		if (pq.empty()) {
			A.push_back(u);
		}
		for (auto &[v, w] : H[u]) {
			if (D[v] == INF) {
				pq.push({D[v] = D[u] + w, v});
			}
		}
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < A.size(); ++i) {
		cout << A[i] << (i == A.size() - 1 ? "\n" : " ");
	}
	return 0;
}
