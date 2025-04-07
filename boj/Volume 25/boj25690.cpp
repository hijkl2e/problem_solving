#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<vector<int>> G, A;
vector<vector<ll>> dp;

void dfs(int x) {
	dp[x][0] = A[x][0];
	dp[x][1] = A[x][1];
	for (int y : G[x]) {
		dfs(y);
		dp[x][0] += min(dp[y][0], dp[y][1]);
		dp[x][1] += dp[y][0];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
	}
	A.assign(N, vector<int>(2));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 2; ++j) {
			cin >> A[i][j];
		}
	}
	dp.assign(N, vector<ll>(2));
	dfs(0);
	ll ans = min(dp[0][0], dp[0][1]);
	cout << ans << "\n";
	return 0;
}
