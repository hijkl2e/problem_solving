#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> dp;

int solve(int x) {
	if (G[x].empty()) {
		return dp[x];
	}
	vector<int> A;
	for (int y : G[x]) {
		A.push_back(solve(y));
	}
	sort(A.rbegin(), A.rend());
	for (int i = 0; i < A.size(); ++i) {
		dp[x] = max(dp[x], A[i] + i + 1);
	}
	return dp[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> par(N);
	for (int i = 0; i < N; ++i) {
		cin >> par[i];
	}
	G.resize(N);
	for (int i = 1; i < N; ++i) {
		G[par[i]].push_back(i);
	}
	dp.resize(N);
	cout << solve(0) << "\n";
	return 0;
}
