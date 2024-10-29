#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

vector<vector<int>> G, dp;

void solve(int u, int p) {
	dp[u].resize(18);
	for (int i = 1; i < 18; ++i) {
		dp[u][i] = i;
	}
	for (int v : G[u]) {
		if (v == p) {
			continue;
		}
		solve(v, u);
		dp[u][0] += dp[v][1];
		dp[u][dp[v][0]] += dp[v][2] - dp[v][1];
	}
	int mini = min_element(dp[u].begin() + 1, dp[u].end()) - dp[u].begin();
	int minv = dp[u][mini];
	dp[u][mini] = INF;
	int minj = min_element(dp[u].begin() + 1, dp[u].end()) - dp[u].begin();
	dp[u] = {mini, minv + dp[u][0], dp[u][minj] + dp[u][0]};
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dp.resize(N + 1);
	solve(1, -1);
	cout << dp[1][1] << "\n";
	return 0;
}
