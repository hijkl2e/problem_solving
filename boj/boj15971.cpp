#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

vector<vector<ii>> G;

int dfs(int u, int p, int g, int sum, int maxv) {
	if (u == g) {
		return sum - maxv;
	}
	for (auto &[v, w] : G[u]) {
		if (v == p) {
			continue;
		}
		int res = dfs(v, u, g, sum + w, max(maxv, w));
		if (res != -1) {
			return res;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, x{}, y{};
	cin >> N >> x >> y;
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	int ans = dfs(x, -1, y, 0, 0);
	cout << ans << "\n";
	return 0;
}
