#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;
using iii = pair<ii, ll>;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{}, P{};
		cin >> N >> M >> P;
		vector<ll> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		vector<vector<ii>> G(N);
		while (M--) {
			int u{}, v{}, w{};
			cin >> u >> v >> w;
			--u, --v;
			G[u].push_back({v, w});
		}
		vector<ii> D(N * N, {INF, INF});
		priority_queue<iii, vector<iii>, greater<iii>> pq;
		pq.push({D[0] = {0, -P}, 0});
		while (pq.size()) {
			auto [d, u] = pq.top(); pq.pop();
			if (D[u] < d) {
				continue;
			}
			int x = u / N, y = u % N;
			for (auto &[nx, w] : G[x]) {
				int ny = A[y] > A[nx] ? y : nx;
				int v = nx * N + ny;
				ii nd{d.first, d.second + w};
				if (nd.second > 0) {
					int z = (nd.second - 1) / A[y] + 1;
					nd.first += z;
					nd.second -= z * A[y];
				}
				if (D[v] > nd) {
					pq.push({D[v] = nd, v});
				}
			}
		}
		ll ans = INF;
		for (int i = 0; i < N; ++i) {
			ans = min(ans, D[(N - 1) * N + i].first);
		}
		cout << (ans == INF ? -1 : ans) << "\n";
	}
	return 0;
}
