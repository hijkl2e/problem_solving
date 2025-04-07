#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> G;

vector<int> bfs(int s) {
	vector<int> D(N + 1, -1);
	queue<int> q;
	D[s] = 0;
	q.push(s);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v : G[u]) {
			if (D[v] == -1) {
				D[v] = D[u] + 1;
				q.push(v);
			}
		}
	}
	return D;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{}, R{};
	cin >> N >> M >> R;
	G.resize(N + 1);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	vector<int> D = bfs(R);
	for (int i = 1; i <= N; ++i) {
		cout << D[i] << "\n";
	}
	return 0;
}
