#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<vector<int>> G;
vector<ll> A, dp;

void dfs(int x) {
	dp[x] = A[x];
	for (int y : G[x]) {
		dfs(y);
		dp[x] += max(dp[y], 0LL);
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
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	dp.resize(N);
	dfs(0);
	cout << dp[0] << "\n";
	return 0;
}
