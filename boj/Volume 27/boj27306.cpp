#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> G, dp;

int solve(int x, int y) {
	if (x == y) {
		y = 0;
	} else if (y && x > y) {
		swap(x, y);
	}
	if (dp[x][y] != -1) {
		return dp[x][y];
	}
	deque<bool> B(2 * N + 1);
	for (int u : G[x]) {
		B[solve(u, y)] = true;
	}
	for (int v : G[y]) {
		B[solve(x, v)] = true;
	}
	int val{};
	while (B[val]) {
		++val;
	}
	return dp[x][y] = val;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{};
	cin >> N >> M;
	G.resize(N + 1);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
	}
	vector<vector<int>> A(N + 1);
	int K{};
	cin >> K;
	while (K--) {
		int v{}, c{};
		cin >> v >> c;
		A[c].push_back(v);
	}
	dp.assign(N + 1, vector<int>(N + 1, -1));
	int x{};
	for (int i = 1; i <= N; ++i) {
		A[i].resize(2);
		x ^= solve(A[i][0], A[i][1]);
	}
	cout << (x ? "Young" : "Cheol") << "\n";
	return 0;
}
