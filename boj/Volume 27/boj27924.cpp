#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G, D;

void dfs(int t, int x, int p) {
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		D[t][y] = D[t][x] + 1;
		dfs(t, y, x);
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
	int a{}, b{}, c{};
	cin >> a >> b >> c;
	D.assign(3, vector<int>(N + 1));
	dfs(0, a, -1);
	dfs(1, b, -1);
	dfs(2, c, -1);
	bool yes{};
	for (int i = 1; i <= N; ++i) {
		if (G[i].size() == 1 && D[0][i] < min(D[1][i], D[2][i])) {
			yes = true;
			break;
		}
	}
	cout << (yes ? "YES" : "NO") << "\n";
	return 0;
}
