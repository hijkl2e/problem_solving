#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

vector<vector<int>> G;
vector<int> dfs_num, dfs_low;
int dfs_cnt;
vector<ii> A;

void dfs(int x, int p) {
	dfs_num[x] = dfs_low[x] = dfs_cnt++;
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		if (dfs_num[y] == -1) {
			dfs(y, x);
			if (dfs_low[y] > dfs_num[x]) {
				A.push_back({min(x, y), max(x, y)});
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
	int V{}, E{};
	cin >> V >> E;
	G.resize(V + 1);
	while (E--) {
		int a{}, b{};
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs_num.assign(V + 1, -1);
	dfs_low.resize(V + 1);
	dfs(1, -1);
	sort(A.begin(), A.end());
	cout << A.size() << "\n";
	for (auto &p : A) {
		cout << p.first << " " << p.second << "\n";
	}
	return 0;
}
