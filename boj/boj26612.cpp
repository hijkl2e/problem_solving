#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> in, out;
int cntr;

void dfs(int x, int p) {
	in[x] = ++cntr;
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		dfs(y, x);
	}
	out[x] = cntr;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, Q{};
	cin >> N >> M >> Q;
	G.resize(3 * N + 1);
	while (M--) {
		int u{}, v{};
		char c{};
		cin >> u >> v >> c;
		u += (c - 'x') * N;
		v += (c - 'x' + 1) % 3 * N;
		G[v].push_back(u);
	}
	vector<int> ind(3 * N + 1);
	for (int u = 1; u <= 3 * N; ++u) {
		for (int v : G[u]) {
			++ind[v];
		}
	}
	in.resize(3 * N + 1);
	out.resize(3 * N + 1);
	for (int i = 1; i <= 3 * N; ++i) {
		if (ind[i] == 0) {
			dfs(i, -1);
		}
	}
	bool yes = find(in.begin() + 1, in.end(), 0) != in.end();
	while (Q--) {
		int u{}, v{};
		char c{};
		cin >> u >> v >> c;
		u += (c - 'x') * N;
		v += (c - 'x' + 1) % 3 * N;
		cout << (yes || (in[u] <= in[v] && in[v] <= out[u])) << "\n";
	}
	return 0;
}
