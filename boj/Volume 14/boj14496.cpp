#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, N{}, M{};
	cin >> a >> b >> N >> M;
	vector<vector<int>> G(N + 1);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	vector<int> D(N + 1, -1);
	queue<int> q;
	D[a] = 0;
	q.push(a);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int y : G[x]) {
			if (D[y] == -1) {
				D[y] = D[x] + 1;
				q.push(y);
			}
		}
	}
	cout << D[b] << "\n";
	return 0;
}
