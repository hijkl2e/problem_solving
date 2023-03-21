#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> A, dp;

int solve(int x) {
	if (dp[x] != -1) {
		return dp[x];
	}
	dp[x] = 0;
	for (int y : G[x]) {
		dp[x] = max(dp[x], solve(y));
	}
	dp[x] += A[x];
	return dp[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, K{};
		cin >> N >> K;
		A.resize(N + 1);
		for (int i = 1; i <= N; ++i) {
			cin >> A[i];
		}
		G.assign(N + 1, {});
		while (K--) {
			int u{}, v{};
			cin >> u >> v;
			G[v].push_back(u);
		}
		int X{};
		cin >> X;
		dp.assign(N + 1, -1);
		cout << solve(X) << "\n";
	}
	return 0;
}
