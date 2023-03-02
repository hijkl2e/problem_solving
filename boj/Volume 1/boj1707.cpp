#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> C;

bool dfs(int x, int c) {
	C[x] = c;
	for (int y : G[x]) {
		if (C[y] == -1 ? !dfs(y, c ^ 1) : (C[x] == C[y])) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int V{}, E{};
		cin >> V >> E;
		G.assign(V + 1, {});
		while (E--) {
			int u{}, v{};
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		C.assign(V + 1, -1);
		bool yes = true;
		for (int i = 1; i <= V; ++i) {
			if (C[i] == -1 && !dfs(i, 0)) {
				yes = false;
				break;
			}
		}
		cout << (yes ? "YES" : "NO") << "\n";
	}
	return 0;
}
