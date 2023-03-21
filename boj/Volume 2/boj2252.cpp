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
	}
	vector<int> ind(N + 1);
	for (int u = 1; u <= N; ++u) {
		for (int v : G[u]) {
			++ind[v];
		}
	}
	queue<int> q;
	for (int i = 1; i <= N; ++i) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}
	vector<int> A;
	while (q.size()) {
		int x = q.front(); q.pop();
		A.push_back(x);
		for (int y : G[x]) {
			if (--ind[y] == 0) {
				q.push(y);
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << A[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
