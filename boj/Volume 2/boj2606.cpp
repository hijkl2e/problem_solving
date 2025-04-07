#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
deque<bool> vst;

void dfs(int x) {
	vst[x] = true;
	for (int y : G[x]) {
		if (vst[y]) {
			continue;
		}
		dfs(y);
	}
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
	dfs(1);
	int ans = accumulate(vst.begin(), vst.end(), 0) - 1;
	cout << ans << "\n";
	return 0;
}
