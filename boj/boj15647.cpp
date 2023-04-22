#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int N;
vector<vector<ii>> G;
vector<int> d, sz;
vector<ll> A;

void dfs1(int u, int p) {
	for (auto &[v, w] : G[u]) {
		if (v == p) {
			continue;
		}
		d[v] = d[u] + w;
		dfs1(v, u);
		sz[u] += sz[v];
	}
}

void dfs2(int u, int p) {
	for (auto &[v, w] : G[u]) {
		if (v == p) {
			continue;
		}
		A[v] = A[u] + (N - 2 * sz[v]) * w;
		dfs2(v, u);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	d.resize(N + 1);
	sz.assign(N + 1, 1);
	dfs1(1, -1);
	A.resize(N + 1);
	A[1] = accumulate(d.begin(), d.end(), 0LL);
	dfs2(1, -1);
	for (int i = 1; i <= N; ++i) {
		cout << A[i] << "\n";
	}
	return 0;
}
