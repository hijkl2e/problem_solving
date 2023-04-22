#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> G(N + 1);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	deque<bool> A(N + 1);
	for (int x : G[1]) {
		A[x] = true;
		for (int y : G[x]) {
			A[y] = true;
		}
	}
	int ans = accumulate(A.begin() + 2, A.end(), 0);
	cout << ans << "\n";
	return 0;
}
