#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

vector<vector<ii>> G, H;
vector<ll> sz, dp;

ll dfs1(int u, int p) {
	ll ret{};
	for (auto &[v, w] : G[u]) {
		if (v == p) {
			continue;
		}
		ret += dfs1(v, u);
		ret += w * sz[v];
		sz[u] += sz[v];
	}
	return ret;
}

void dfs2(int u, int p) {
	for (auto &[v, w] : G[u]) {
		if (v == p) {
			continue;
		}
		dp[v] = dp[u] + (G.size() - 2 * sz[v] - 1) * w;
		dfs2(v, u);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	int M{};
	cin >> M;
	H.resize(M + 1);
	for (int i = 0; i < M - 1; ++i) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		H[u].push_back({v, w});
		H[v].push_back({u, w});
	}
	ll ans = 1LL * N * M;
	int x{}, y{};
	for (int i = 0; i < 2; ++i) {
		sz.assign(N + 1, 1);
		dp.resize(N + 1);
		dp[1] = dfs1(1, -1);
		dfs2(1, -1);
		x = min_element(dp.begin() + 1, dp.end()) - dp.begin();
		ans += dp[x] * M;
		swap(N, M);
		swap(G, H);
		swap(x, y);
	}
	cout << x << " " << y << "\n";
	cout << ans << "\n";
	return 0;
}
