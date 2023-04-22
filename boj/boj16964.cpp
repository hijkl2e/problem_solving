#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
queue<int> q;

void dfs(int x) {
	q.pop();
	while (q.size() && binary_search(G[x].begin(), G[x].end(), q.front())) {
		dfs(q.front());
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= N; ++i) {
		sort(G[i].begin(), G[i].end());
	}
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		q.push(x);
	}
	bool yes = q.front() == 1;
	dfs(1);
	yes &= q.empty();
	cout << yes << "\n";
	return 0;
}
