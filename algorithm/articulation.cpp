#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> dfs_num, dfs_low;
int dfs_cnt;

void dfs(int x, int p) {
	dfs_num[x] = dfs_low[x] = dfs_cnt++;
	int child{};
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		if (dfs_num[y] == -1) {
			dfs(y, x);
			if (dfs_low[y] >= dfs_num[x] && p != -1) {
				// articulation point
			}
			if (dfs_low[y] > dfs_num[x]) {
				// articulation bridge
			}
			dfs_low[x] = min(dfs_low[x], dfs_low[y]);
			++child;
		} else {
			dfs_low[x] = min(dfs_low[x], dfs_num[y]);
		}
	}
	if (p == -1 && child > 1) {
		// articulation point
	}
}
