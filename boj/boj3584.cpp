#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> d;

void dfs(int x) {
	for (int y : G[x]) {
		d[y] = d[x] + 1;
		dfs(y);
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
		G.assign(N + 1, {});
		vector<int> par(N + 1, -1);
		for (int i = 0; i < N - 1; ++i) {
			int u{}, v{};
			cin >> u >> v;
			G[u].push_back(v);
			par[v] = u;
		}
		int a{}, b{};
		cin >> a >> b;
		d.resize(N + 1);
		int r = find(par.begin() + 1, par.end(), -1) - par.begin();
		dfs(r);
		if (d[a] > d[b]) {
			swap(a, b);
		}
		while (d[a] < d[b]) {
			b = par[b];
		}
		while (a != b) {
			a = par[a];
			b = par[b];
		}
		cout << a << "\n";
	}
	return 0;
}
