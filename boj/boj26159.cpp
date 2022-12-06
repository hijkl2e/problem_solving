#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

vector<vector<int>> G;
vector<ll> dp;

ll dfs(int x, int p) {
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		dp[x] += dfs(y, x);
	}
	return dp[x];
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
	vector<ll> A(N - 1);
	for (int i = 0; i < N - 1; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	dp.assign(N + 1, 1);
	dfs(1, -1);
	for (int i = 1; i <= N; ++i) {
		dp[i] *= N - dp[i];
	}
	sort(dp.rbegin(), dp.rend());
	ll ans{};
	for (int i = 0; i < N - 1; ++i) {
		ans = (ans + dp[i] * A[i]) % MOD;
	}
	cout << ans << "\n";
	return 0;
}
