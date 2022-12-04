#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> dfs_num, dfs_low;
int dfs_cnt;
deque<bool> A;

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
				A[x] = true;
			}
			dfs_low[x] = min(dfs_low[x], dfs_low[y]);
			++child;
		} else {
			dfs_low[x] = min(dfs_low[x], dfs_num[y]);
		}
	}
	if (p == -1 && child > 1) {
		A[x] = true;
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
	A.resize(V + 1);
	for (int i = 1; i <= V; ++i) {
		if (dfs_num[i] == -1) {
			dfs(i, -1);
		}
	}
	vector<int> B;
	for (int i = 1; i <= V; ++i) {
		if (A[i]) {
			B.push_back(i);
		}
	}
	cout << B.size() << "\n";
	for (int i = 0; i < B.size(); ++i) {
		cout << B[i] << (i == B.size() - 1 ? "" : " ");
	}
	cout << "\n";
	return 0;
}
