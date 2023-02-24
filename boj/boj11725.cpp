#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> par;

void dfs(int x, int p) {
	par[x] = p;
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		dfs(y, x);
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
	par.resize(N + 1);
	dfs(1, -1);
	for (int i = 2; i <= N; ++i) {
		cout << par[i] << "\n";
	}
	return 0;
}
