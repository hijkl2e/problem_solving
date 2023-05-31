#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const ll INF = 4e18;
const ll MOD = 998244353;

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
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({D[1] = 0, 1});
	while (pq.size()) {
		auto [d, u] = pq.top(); pq.pop();
		for (auto &[v, w] : G[u]) {
			if (D[v] > D[u] + w) {
				pq.push({D[v] = D[u] + w, v});
			}
		}
	}
	vector<vector<ii>> H(N + 1);
	for (int u = 1; u <= N; ++u) {
		for (auto &[v, w] : G[u]) {
			if (D[v] == D[u] + w) {
				H[u].push_back({v, w});
			}
		}
	}
	vector<int> ind(N + 1);
	for (int u = 1; u <= N; ++u) {
		for (auto &[v, w] : H[u]) {
			++ind[v];
		}
	}
	vector<ll> dp(N + 1);
	queue<int> q;
	if (ind[1] == 0) {
		dp[1] = 1;
		q.push(1);
	}
	while (q.size()) {
		int u = q.front(); q.pop();
		for (auto &[v, w] : H[u]) {
			dp[v] = (dp[v] + dp[u]) % MOD;
			if (--ind[v] == 0) {
				q.push(v);
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (ind[i]) {
			dp[i] = -1;
		}
	}
	for (int i = 1; i <= N; ++i) {
		cout << dp[i] << "\n";
	}
	return 0;
}
