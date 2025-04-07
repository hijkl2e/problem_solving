#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<vector<ii>> G(N + 1);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
	}
	vector<priority_queue<ii>> D(N + 1);
	priority_queue<iii, vector<iii>, greater<iii>> pq;
	D[1].push({0, 0});
	pq.push({0, 0, 1});
	int p = 1;
	while (pq.size()) {
		auto [d, n, u] = pq.top(); pq.pop();
		if (D[u].top() < make_pair(d, n)) {
			continue;
		}
		for (auto &[v, w] : G[u]) {
			if (D[v].size() < K || D[v].top() > make_pair(d + w, p)) {
				if (D[v].size() == K) {
					D[v].pop();
				}
				D[v].push({d + w, p});
				pq.push({d + w, p++, v});
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		cout << (D[i].size() == K ? D[i].top().first : -1) << "\n";
	}
	return 0;
}
