#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> G(N + 1);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
	}
	vector<int> dp(N + 1, 1);
	for (int i = 1; i <= N; ++i) {
		for (int x : G[i]) {
			dp[x] = max(dp[x], dp[i] + 1);
		}
	}
	for (int i = 1; i <= N; ++i) {
		cout << dp[i] << (i == N ? "\n" : " ");
	}
	return 0;
}
