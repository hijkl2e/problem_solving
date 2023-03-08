#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G, dp;
vector<int> A;

void dfs1(int x, int p) {
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		dfs1(y, x);
		for (int i = 0; i < 3; ++i) {
			dp[x][i] += max(dp[y][(i + 1) % 3], dp[y][(i + 2) % 3]);
		}
	}
}

void dfs2(int x, int p, int c) {
	A[x] = c;
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		dfs2(y, x, (c + (dp[y][(c + 1) % 3] > dp[y][(c + 2) % 3] ? 1 : 2)) % 3);
	}
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
	dp.assign(N + 1, vector<int>(3));
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> dp[i][j];
		}
	}
	dfs1(1, -1);
	A.resize(N + 1);
	int maxi = max_element(dp[1].begin(), dp[1].end()) - dp[1].begin();
	dfs2(1, -1, maxi);
	cout << dp[1][maxi] << "\n";
	string rgb = "RGB";
	for (int i = 1; i <= N; ++i) {
		cout << rgb[A[i]];
	}
	cout << "\n";
	return 0;
}
