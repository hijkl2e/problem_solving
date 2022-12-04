#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		int N{}, M{};
		cin >> N >> M;
		vector<set<ii>> G(N + 1);
		while (M--) {
			int a{}, b{}, c{};
			cin >> a >> b >> c;
			G[a].insert({b, c});
			G[b].insert({a, c});
		}
		for (int u = 1; u <= N; ++u) {
			if (G[u].size() != 2) {
				continue;
			}
			auto &[v1, w1] = *G[u].begin();
			auto &[v2, w2] = *++G[u].begin();
			G[v1].erase({u, w1});
			G[v2].erase({u, w2});
			G[v1].insert({v2, w1 + w2});
			G[v2].insert({v1, w1 + w2});
			G[u].clear();
		}
		int cnt{};
		for (int u = 1; u <= N; ++u) {
			for (auto &[v, w] : G[u]) {
				cnt += u <= v;
			}
		}
		if (tc) {
			cout << "\n";
		}
		cout << cnt << "\n";
		for (int u = 1; u <= N; ++u) {
			for (auto &[v, w] : G[u]) {
				if (u <= v) {
					cout << u << " " << v << " " << w << "\n";
				}
			}
		}
	}
	return 0;
}
