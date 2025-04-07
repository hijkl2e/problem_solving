#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

vector<vector<int>> G;
vector<int> A;
vector<ll> dp;

ll solve(int);

void dfs(int u, int x, int k) {
	if (k == 0) {
		return;
	}
	dp[x] = (dp[x] + solve(u)) % MOD;
	for (int v : G[u]) {
		dfs(v, x, k - 1);
	}
}

ll solve(int x) {
	if (dp[x] != -1) {
		return dp[x];
	}
	dp[x] = G[x].empty();
	for (int y : G[x]) {
		dfs(y, x, A[x]);
	}
	return dp[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		int p{};
		cin >> p;
		G[p].push_back(i);
	}
	A.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	dp.assign(N + 1, -1);
	int r = G[0][0];
	cout << solve(r) << "\n";
	return 0;
}
