#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> d;

void dfs(int x, int p) {
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		d[y] = d[x] + 1;
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
	d.resize(N + 1);
	dfs(1, -1);
	bool yes{};
	for (int i = 2; i <= N; ++i) {
		if (G[i].size() == 1) {
			yes ^= d[i] % 2;
		}
	}
	cout << (yes ? "Yes" : "No") << "\n";
	return 0;
}
