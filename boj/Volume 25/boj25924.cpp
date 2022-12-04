#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> d, par;
int cnt1, cnt2;

void dfs(int x, int p, bool f) {
	cout << x << "\n";
	for (int y : G[x]) {
		if (y == p || (f && y == par[x])) {
			continue;
		}
		if (cnt2) {
			--cnt2;
			dfs(y, x, false);
			cout << x << "\n";
		}
	}
	if (f && cnt1) {
		--cnt1;
		dfs(par[x], x, true);
	}
}

int bfs(int x) {
	fill(d.begin(), d.end(), -1);
	fill(par.begin(), par.end(), -1);
	queue<int> q;
	d[x] = 0;
	q.push(x);
	while (q.size()) {
		x = q.front(); q.pop();
		for (int y : G[x]) {
			if (d[y] == -1) {
				d[y] = d[x] + 1;
				q.push(y);
				par[y] = x;
			}
		}
	}
	return x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	d.resize(N + 1);
	par.resize(N + 1);
	int u = bfs(bfs(1));
	cnt1 = min(K, d[u]);
	cnt2 = min((K - cnt1) / 2, N - cnt1 - 1);
	int M = cnt1 + cnt2 + 1;
	int L = cnt1 + 2 * cnt2;
	cout << M << "\n" << L << "\n";
	dfs(u, -1, true);
	return 0;
}
