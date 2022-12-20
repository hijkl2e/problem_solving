#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

vector<vector<int>> G, dist, go;

void dfs(int s, int x, int p) {
	go[s][x] = p == -1 ? -1 : p == s ? x : go[s][p];
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		dist[s][y] = dist[s][x] + 1;
		dfs(s, y, x);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cin.ignore();
		string S;
		getline(cin, S);
		S = "#" + S;
		G.assign(N + 1, {});
		for (int i = 0; i < N - 1; ++i) {
			int u{}, v{};
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dist.assign(N + 1, vector<int>(N + 1));
		go.assign(N + 1, vector<int>(N + 1));
		for (int i = 1; i <= N; ++i) {
			dist[i][i] = 0;
			dfs(i, i, -1);
		}
		vector<iii> A;
		for (int i = 1; i <= N; ++i) {
			for (int j = i; j <= N; ++j) {
				A.push_back({dist[i][j], i, j});
			}
		}
		sort(A.begin(), A.end());
		vector<vector<int>> dp(N + 1, vector<int>(N + 1));
		for (auto &[d, u, v] : A) {
			if (u == v) {
				dp[u][v] = 1;
				continue;
			}
			if (S[u] == S[v]) {
				dp[u][v] = (d > 1 ? dp[go[u][v]][go[v][u]] : 0) + 2;
			} else {
				dp[u][v] = max(dp[go[u][v]][v], dp[u][go[v][u]]);
			}
			dp[v][u] = dp[u][v];
		}
		int ans{};
		for (int i = 1; i <= N; ++i) {
			for (int j = i; j <= N; ++j) {
				ans = max(ans, dp[i][j]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
