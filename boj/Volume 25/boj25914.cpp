#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G, H;
vector<int> dfs_num, dfs_low;
int dfs_cnt;
deque<bool> A, vst;

void dfs(int x, int p) {
	dfs_num[x] = dfs_low[x] = dfs_cnt++;
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		if (dfs_num[y] == -1) {
			dfs(y, x);
			if (dfs_low[y] > dfs_num[x]) {
				H[x].push_back(y);
				H[y].push_back(x);
			}
			dfs_low[x] = min(dfs_low[x], dfs_low[y]);
		} else {
			dfs_low[x] = min(dfs_low[x], dfs_num[y]);
		}
	}
}

int bfs(int x) {
	int cnt1{}, cnt2{};
	queue<int> q;
	vst[x] = true;
	q.push(x);
	while (q.size()) {
		x = q.front(); q.pop();
		for (int y : H[x]) {
			if (vst[y]) {
				continue;
			}
			vst[y] = true;
			q.push(y);
		}
		++cnt1;
		if (A[x]) {
			++cnt2;
		}
	}
	return cnt2 ? cnt1 - cnt2 : 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	G.resize(N + 1);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	A.resize(N + 1);
	while (K--) {
		int x{};
		cin >> x;
		A[x] = true;
	}
	int C{};
	cin >> C;
	H.resize(N + 1);
	dfs_num.assign(N + 1, -1);
	dfs_low.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		if (dfs_num[i] == -1) {
			dfs(i, -1);
		}
	}
	vst.resize(N + 1);
	int res{};
	for (int i = 1; i <= N; ++i) {
		if (!vst[i]) {
			res ^= bfs(i);
		}
	}
	cout << (res ? C : (1 - C)) << "\n";
	return 0;
}
