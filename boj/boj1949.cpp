#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G, dp;
vector<int> A;

void dfs(int x, int p) {
	dp[x][1] = A[x];
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		dfs(y, x);
		dp[x][0] += max(dp[y][0], dp[y][1]);
		dp[x][1] += dp[y][0];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	A.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dp.assign(N + 1, vector<int>(2));
	dfs(1, -1);
	int ans = max(dp[1][0], dp[1][1]);
	cout << ans << "\n";
	return 0;
}
