#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<ii>> G(N + 1);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
	}
	vector<ll> D(N + 1, INF);
	D[1] = 0;
	bool flag{};
	for (int i = 0; i < N; ++i) {
		for (int u = 1; u <= N; ++u) {
			if (D[u] == INF) {
				continue;
			}
			for (auto &[v, w] : G[u]) {
				if (D[v] > D[u] + w) {
					D[v] = D[u] + w;
					if (i == N - 1) {
						flag = true;
					}
				}
			}
		}
	}
	if (flag) {
		cout << "-1\n";
		return 0;
	}
	for (int i = 2; i <= N; ++i) {
		cout << (D[i] == INF ? -1 : D[i]) << "\n";
	}
	return 0;
}
