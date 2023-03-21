#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<ii>> G(N + 1);
	vector<vector<ii>> H(N + 1);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		H[v].push_back({u, w});
	}
	int s{}, g{};
	cin >> s >> g;
	vector<int> ind(N + 1);
	for (int u = 1; u <= N; ++u) {
		for (auto &[v, w] : G[u]) {
			++ind[v];
		}
	}
	queue<int> q;
	q.push(s);
	vector<int> dp(N + 1);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (auto &[v, w] : G[u]) {
			dp[v] = max(dp[v], dp[u] + w);
			if (--ind[v] == 0) {
				q.push(v);
			}
		}
	}
	deque<bool> vst(N + 1);
	vst[g] = true;
	q.push(g);
	int cnt{};
	while (q.size()) {
		int u = q.front(); q.pop();
		for (auto &[v, w] : H[u]) {
			if (dp[u] == dp[v] + w) {
				++cnt;
				if (!vst[v]) {
					vst[v] = true;
					q.push(v);
				}
			}
		}
	}
	cout << dp[g] << "\n" << cnt << "\n";
	return 0;
}
