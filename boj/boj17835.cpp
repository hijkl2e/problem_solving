#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<vector<ii>> G(N + 1);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[v].push_back({u, w});
	}
	vector<ll> D(N + 1, INF);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	while (K--) {
		int x{};
		cin >> x;
		pq.push({D[x] = 0, x});
	}
	while (pq.size()) {
		auto [d, u] = pq.top();
		pq.pop();
		if (D[u] < d) {
			continue;
		}
		for (auto &[v, w] : G[u]) {
			if (D[v] > D[u] + w) {
				pq.push({D[v] = D[u] + w, v});
			}
		}
	}
	auto it = max_element(D.begin() + 1, D.end());
	cout << (it - D.begin()) << "\n";
	cout << *it << "\n";
	return 0;
}
