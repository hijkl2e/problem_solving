#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> ind, D;

void dfs(int x) {
	for (int y : G[x]) {
		if (ind[y] < 1 && D[y] == 0) {
			D[y] = D[x] + 1;
			dfs(y);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N + 1);
	for (int i = 0; i < N; ++i) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ind.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		ind[i] = G[i].size() - 1;
	}
	queue<int> q;
	for (int i = 1; i <= N; ++i) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int y : G[x]) {
			if (--ind[y] == 0) {
				q.push(y);
			}
		}
	}
	D.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		if (ind[i] > 0) {
			dfs(i);
		}
	}
	for (int i = 1; i <= N; ++i) {
		cout << D[i] << (i == N ? "\n" : " ");
	}
	return 0;
}
