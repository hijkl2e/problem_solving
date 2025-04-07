#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, s{}, t{}, M{};
	cin >> N >> s >> t >> M;
	vector<vector<ii>> G(N);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
	}
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<ll> D(N, INF);
	D[s] = -A[s];
	for (int i = 0; i < 2 * N; ++i) {
		for (int u = 0; u < N; ++u) {
			if (D[u] == INF) {
				continue;
			}
			for (auto &[v, w] : G[u]) {
				if (D[v] > D[u] + w - A[v]) {
					D[v] = i < N - 1 ? D[u] + w - A[v] : -INF;
				}
			}
		}
	}
	if (abs(D[t]) == INF) {
		cout << (D[t] == INF ? "gg" : "Gee") << "\n";
	} else {
		cout << -D[t] << "\n";
	}
	return 0;
}
