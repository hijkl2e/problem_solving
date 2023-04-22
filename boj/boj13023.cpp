#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> A;

bool dfs(int x) {
	if (find(A.begin(), A.end(), x) != A.end()) {
		return false;
	}
	A.push_back(x);
	if (A.size() == 5) {
		return true;
	}
	for (int y : G[x]) {
		if (dfs(y)) {
			return true;
		}
	}
	A.pop_back();
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	G.resize(N);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bool yes{};
	for (int i = 0; i < N; ++i) {
		if (dfs(i)) {
			yes = true;
			break;
		}
	}
	cout << yes << "\n";
	return 0;
}
