#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

vector<vector<ii>> G;
vector<int> d, par;

int bfs(int s) {
	int ret = s;
	queue<int> q;
	d[s] = 0;
	par[s] = -1;
	q.push(s);
	while (q.size()) {
		int u = q.front(); q.pop();
		if (d[ret] < d[u]) {
			ret = u;
		}
		for (auto &[v, w] : G[u]) {
			if (v == par[u]) {
				continue;
			}
			d[v] = d[u] + w;
			par[v] = u;
			q.push(v);
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, L{};
	cin >> N >> M >> L;
	G.resize(N);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	d.assign(N, -1);
	par.assign(N, -1);
	vector<int> A;
	int ans{};
	for (int i = 0; i < N; ++i) {
		if (d[i] != -1) {
			continue;
		}
		int x = bfs(bfs(i));
		int y = d[x];
		int minv = y;
		while (par[x] != -1) {
			x = par[x];
			minv = min(minv, max(d[x], y - d[x]));
		}
		ans = max(ans, y);
		A.push_back(minv);
	}
	sort(A.rbegin(), A.rend());
	ans = max(ans, A.size() == 1 ? -1 : (A[1] + L + max(A[0], A.size() == 2 ? -1 : (A[2] + L))));
	cout << ans << "\n";
	return 0;
}
