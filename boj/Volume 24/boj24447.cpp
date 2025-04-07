#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int N;
vector<vector<int>> G;

ll bfs(int s) {
	vector<int> D(N + 1, -1);
	vector<int> T(N + 1);
	queue<int> q;
	int cnt{};
	D[s] = 0, T[s] = ++cnt;
	q.push(s);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v : G[u]) {
			if (D[v] == -1) {
				D[v] = D[u] + 1;
				T[v] = ++cnt;
				q.push(v);
			}
		}
	}
	ll ret{};
	for (int i = 1; i <= N; ++i) {
		ret += 1LL * D[i] * T[i];
	}
	return ret;
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
	for (int i = 1; i <= N; ++i) {
		sort(G[i].begin(), G[i].end());
	}
	cout << bfs(R) << "\n";
	return 0;
}
