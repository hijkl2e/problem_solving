#include <bits/stdc++.h>

using namespace std;

const int MOD = 9901;

int N;
vector<deque<bool>> G;
vector<vector<int>> dp;

int solve(int u, int x) {
	if (dp[u][x] != -1) {
		return dp[u][x];
	} else if (x == 0) {
		return dp[u][x] = G[u][N - 1];
	}
	int &val = dp[u][x];
	val = 0;
	for (int i = 0; i < N - 1; ++i) {
		if ((x & (1 << i)) && G[u][i]) {
			val += solve(i, x & ~(1 << i));
		}
	}
	return val;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int K{};
		cin >> N >> K;
		G.assign(N, deque<bool>(N, true));
		while (K--) {
			int u{}, v{};
			cin >> u >> v;
			--u, --v;
			G[u][v] = G[v][u] = false;
		}
		dp.assign(N, vector<int>(1 << (N - 1), -1));
		int ans = 4951 * solve(N - 1, (1 << (N - 1)) - 1) % MOD;
		cout << "Case #" << tc << ": " << ans << "\n";
	}
	return 0;
}
