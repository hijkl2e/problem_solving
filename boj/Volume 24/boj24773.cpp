#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> dfs_num, dfs_low;
int dfs_cnt;
bool yes;

void dfs(int x, int p) {
	dfs_num[x] = dfs_low[x] = dfs_cnt++;
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		if (dfs_num[y] == -1) {
			dfs(y, x);
			if (dfs_low[y] > dfs_num[x]) {
				yes = true;
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
	int P{}, C{};
	while (cin >> P >> C, P) {
		G.assign(P, vector<int>());
		while (C--) {
			int a{}, b{};
			cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		dfs_num.assign(P, -1);
		dfs_low.resize(P);
		dfs_cnt = 0;
		yes = false;
		dfs(0, -1);
		yes |= dfs_cnt < P;
		cout << (yes ? "Yes" : "No") << "\n";
	}
	return 0;
}
