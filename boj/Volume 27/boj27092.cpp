#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

vector<vector<int>> G, dp;
ll ans;

void dfs(int x) {
	if (G[x].empty()) {
		dp[x].push_back(1);
		return;
	}
	for (int y : G[x]) {
		dfs(y);
	}
	sort(G[x].begin(), G[x].end(), [&](int a, int b) {
		return dp[a].size() > dp[b].size();
	});
	int k = G[x].size();
	for (int i = 0; k > 1; ++i) {
		ll mul = 1, sum = 0;
		for (int j = k - 1; j >= 0; --j) {
			int y = G[x][j];
			int &z = dp[y][dp[y].size() - i - 1];
			mul = mul * (z + 1) % MOD;
			sum += z;
			if (j == 0) {
				z = sum;
			}
		}
		ans = (ans + mul - sum - 1) % MOD;
		while (k > 1 && dp[G[x][k - 1]].size() == i + 1) {
			--k;
		}
	}
	swap(dp[x], dp[G[x][0]]);
	dp[x].push_back(1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> P(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> P[i];
	}
	G.resize(N + 1);
	for (int i = 2; i <= N; ++i) {
		G[P[i]].push_back(i);
	}
	dp.resize(N + 1);
	dfs(1);
	ans = (ans + MOD) % MOD;
	cout << ans << "\n";
	return 0;
}
