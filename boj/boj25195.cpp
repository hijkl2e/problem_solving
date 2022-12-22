#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
deque<bool> A;

bool dfs(int x) {
	if (A[x]) {
		return false;
	} else if (G[x].empty()) {
		return true;
	}
	for (int y : G[x]) {
		if (dfs(y)) {
			return true;
		}
	}
	return false;
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
	}
	int S{};
	cin >> S;
	A.resize(N + 1);
	while (S--) {
		int x{};
		cin >> x;
		A[x] = true;
	}
	cout << (dfs(1) ? "yes" : "Yes") << "\n";
	return 0;
}
