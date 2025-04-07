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
	int N{}, x{}, y{}, M{};
	cin >> N >> x >> y >> M;
	G.resize(N + 1);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	d.resize(N + 1, -1);
	d[x] = 0;
	dfs(x, -1);
	cout << d[y] << "\n";
	return 0;
}
