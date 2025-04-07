#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> G;
vector<int> A;

int dfs(int x, int p) {
	int maxv{};
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		int res = dfs(y, x);
		A.push_back(min(maxv, res));
		maxv = max(maxv, res);
	}
	return maxv + 1;
}

int bfs(int x) {
	deque<bool> vst(N + 1);
	queue<int> q;
	vst[x] = true;
	q.push(x);
	while (q.size()) {
		x = q.front(); q.pop();
		for (int y : G[x]) {
			if (!vst[y]) {
				vst[y] = true;
				q.push(y);
			}
		}
	}
	return x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{};
	cin >> N >> K;
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int u = bfs(1);
	int ans = dfs(u, -1) - 1;
	sort(A.rbegin(), A.rend());
	for (int i = 0; i < A.size() && i < K; ++i) {
		ans += A[i];
	}
	cout << ans << "\n";
	return 0;
}
