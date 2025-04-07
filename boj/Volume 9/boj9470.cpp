#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int K{}, N{}, M{};
		cin >> K >> N >> M;
		vector<vector<int>> G(N + 1);
		vector<vector<int>> H(N + 1);
		while (M--) {
			int u{}, v{};
			cin >> u >> v;
			G[u].push_back(v);
			H[v].push_back(u);
		}
		vector<int> ind(N + 1);
		for (int u = 1; u <= N; ++u) {
			for (int v : G[u]) {
				++ind[v];
			}
		}
		vector<int> dp(N + 1);
		queue<int> q;
		for (int i = 1; i <= N; ++i) {
			if (ind[i] == 0) {
				q.push(i);
			}
		}
		while (q.size()) {
			int u = q.front(); q.pop();
			int maxv{};
			bool flag = true;
			for (int v : H[u]) {
				if (maxv < dp[v]) {
					maxv = dp[v];
					flag = false;
				} else if (maxv == dp[v]) {
					flag = true;
				}
			}
			dp[u] = maxv + flag;
			for (int v : G[u]) {
				if (--ind[v] == 0) {
					q.push(v);
				}
			}
		}
		cout << K << " " << dp[N] << "\n";
	}
	return 0;
}
