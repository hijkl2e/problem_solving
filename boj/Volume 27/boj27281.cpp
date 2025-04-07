#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;
using edge = tuple<int, int, int>;

const int INF = 1e9 + 7;

int N;
vector<vector<edge>> G;

ll solve(int x) {
	vector<ll> D(N + 1, 4e18);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({D[1] = 0, 1});
	while (pq.size()) {
		auto [d, u] = pq.top(); pq.pop();
		if (D[u] < d) {
			continue;
		}
		for (auto &[v, t, s] : G[u]) {
			ll nd = d + t + max(s - x, 0);
			if (D[v] > nd) {
				pq.push({D[v] = nd, v});
			}
		}
	}
	return D[N];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{}, T{};
	cin >> N >> M >> T;
	G.resize(N + 1);
	while (M--) {
		int u{}, v{}, t{}, s{};
		cin >> u >> v >> t >> s;
		G[u].push_back({v, t, s});
		G[v].push_back({u, t, s});
	}
	int lo = -1, hi = INF;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (solve(mid) <= T) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout << (hi == INF ? -1 : hi) << "\n";
	return 0;
}
