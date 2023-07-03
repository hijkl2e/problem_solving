#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
deque<bool> vst;

int dfs(int x) {
	vst[x] = true;
	int ret = G[x].size() % 2;
	for (int y : G[x]) {
		if (vst[y]) {
			continue;
		}
		ret += dfs(y);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	G.resize(N + 1);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	vst.resize(N + 1);
	int ans{};
	for (int i = 1; i <= N; ++i) {
		if (vst[i] || G[i].empty()) {
			continue;
		}
		ans += max(dfs(i) / 2, 1);
	}
	cout << ans << "\n";
	return 0;
}
