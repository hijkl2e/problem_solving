#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> dfs_num, dfs_low;
int dfs_cnt;

void dfs(int x, int p) {
	dfs_num[x] = dfs_low[x] = dfs_cnt++;
	for (int &y : G[x]) {
		if (y == p || y == -1) {
			continue;
		}
		if (dfs_num[y] == -1) {
			dfs(y, x);
			if (dfs_low[y] > dfs_num[x]) {
				y = -1;
				continue;
			}
			dfs_low[x] = min(dfs_low[x], dfs_low[y]);
		} else {
			dfs_low[x] = min(dfs_low[x], dfs_num[y]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	G.resize(N);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs_num.assign(N, -1);
	dfs_low.resize(N);
	dfs(0, -1);
	dfs_num.assign(N, -1);
	dfs_cnt = 0;
	dfs(0, -1);
	cout << dfs_cnt << "\n";
	return 0;
}
