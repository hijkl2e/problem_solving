#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<vector<int>> G;
vector<ll> dp;

ll solve(int x) {
	for (int y : G[x]) {
		dp[x] += solve(y);
	}
	return dp[x] = max(dp[x], 0LL);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N + 1);
	dp.resize(N + 1);
	for (int i = 2; i <= N; ++i) {
		char c{};
		int p{};
		cin >> c >> dp[i] >> p;
		dp[i] *= c == 'S' ? 1 : -1;
		G[p].push_back(i);
	}
	cout << solve(1) << "\n";
	return 0;
}
