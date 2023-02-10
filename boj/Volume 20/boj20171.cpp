#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
deque<bool> A;

bool dfs(int x, int p) {
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		A[x] |= dfs(y, x);
	}
	return A[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	A.resize(N + 1);
	int x{};
	for (int i = 0; i < K; ++i) {
		cin >> x;
		A[x] = true;
	}
	dfs(x, -1);
	int ans = accumulate(A.begin(), A.end(), 0);
	cout << ans << "\n";
	return 0;
}
