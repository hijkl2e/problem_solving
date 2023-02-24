#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

vector<vector<ii>> G;
vector<int> d;

int bfs(int u) {
	fill(d.begin(), d.end(), -1);
	queue<int> q;
	d[u] = 0;
	q.push(u);
	while (q.size()) {
		u = q.front(); q.pop();
		for (auto &[v, w] : G[u]) {
			if (d[v] == -1) {
				d[v] = d[u] + w;
				q.push(v);
			}
		}
	}
	return max_element(d.begin(), d.end()) - d.begin();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	d.resize(N + 1);
	int u = bfs(bfs(1));
	cout << d[u] << "\n";
	return 0;
}
