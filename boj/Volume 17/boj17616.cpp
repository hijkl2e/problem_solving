#include <bits/stdc++.h>

using namespace std;

deque<bool> A;

int solve(vector<vector<int>> &G, int x) {
	int ret = 1;
	A[x] = true;
	for (int y : G[x]) {
		if (A[y]) {
			continue;
		}
		ret += solve(G, y);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, X{};
	cin >> N >> M >> X;
	vector<vector<int>> G(N + 1);
	vector<vector<int>> H(N + 1);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		H[v].push_back(u);
	}
	A.resize(N + 1);
	int u = solve(H, X);
	A.assign(N + 1, false);
	int v = N - solve(G, X) + 1;
	cout << u << " " << v << "\n";
	return 0;
}
