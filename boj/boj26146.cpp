#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G, H;
deque<bool> vst;

void dfs(int x, bool rev) {
	vst[x] = true;
	for (int y : rev ? H[x] : G[x]) {
		if (!vst[y]) {
			dfs(y, rev);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	G.resize(N + 1);
	H.resize(N + 1);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		H[v].push_back(u);
	}
	vst.resize(N + 1);
	dfs(1, false);
	bool yes = accumulate(vst.begin(), vst.end(), 0) == N;
	fill(vst.begin(), vst.end(), false);
	dfs(1, true);
	yes &= accumulate(vst.begin(), vst.end(), 0) == N;
	cout << (yes ? "Yes" : "No") << "\n";
	return 0;
}
