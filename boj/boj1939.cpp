#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int N, M;
vector<vector<ii>> G;

bool bfs(int s, int g, int c) {
	deque<bool> A(N + 1);
	queue<int> q;
	A[s] = true;
	q.push(s);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (auto &[v, w] : G[u]) {
			if (w < c || A[v]) {
				continue;
			}
			A[v] = true;
			q.push(v);
		}
	}
	return A[g];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	G.resize(N + 1);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	int s{}, g{};
	cin >> s >> g;
	int lo = 1, hi = 1e9 + 7;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (bfs(s, g, mid)) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << lo << "\n";
	return 0;
}
