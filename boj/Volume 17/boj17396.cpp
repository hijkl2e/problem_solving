#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<vector<ii>> G(N);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	vector<ll> D(N, INF);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({D[0] = 0, 0});
	while (pq.size()) {
		auto [d, u] = pq.top(); pq.pop();
		if (D[u] < d || A[u]) {
			continue;
		}
		for (auto &[v, w] : G[u]) {
			if (D[v] > D[u] + w) {
				pq.push({D[v] = D[u] + w, v});
			}
		}
	}
	cout << (D[N - 1] == INF ? -1 : D[N - 1]) << "\n";
	return 0;
}
