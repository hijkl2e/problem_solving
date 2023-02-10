#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> G;

vector<int> bfs(int s) {
	vector<int> ret(N + 1);
	queue<int> q;
	int cnt{};
	ret[s] = ++cnt;
	q.push(s);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v : G[u]) {
			if (ret[v] == 0) {
				ret[v] = ++cnt;
				q.push(v);
			}
		}
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
		sort(G[i].rbegin(), G[i].rend());
	}
	vector<int> A = bfs(R);
	for (int i = 1; i <= N; ++i) {
		cout << A[i] << "\n";
	}
	return 0;
}
