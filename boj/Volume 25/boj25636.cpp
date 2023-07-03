#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;
using iii = pair<ii, ll>;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<vector<ii>> G(N + 1);
	int M{};
	cin >> M;
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	int s{}, t{};
	cin >> s >> t;
	vector<ii> D(N + 1, {INF, INF});
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	pq.push({D[s] = {0, -A[s]}, s});
	while (pq.size()) {
		auto [d, u] = pq.top(); pq.pop();
		if (D[u] < d) {
			continue;
		}
		for (auto &[v, w] : G[u]) {
			ii nd = {d.first + w, d.second - A[v]};
			if (D[v] > nd) {
				pq.push({D[v] = nd, v});
			}
		}
	}
	if (D[t].first == INF) {
		cout << "-1\n";
	} else {
		cout << D[t].first << " " << -D[t].second << "\n";
	}
	return 0;
}
