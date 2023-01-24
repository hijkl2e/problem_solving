#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<vector<int>> G;
vector<int> sz, dep, par, top;

void dfs1(int u) {
	sz[u] = 1;
	for (auto &v : G[u]) {
		if (par[u] == v) {
			continue;
		}
		dep[v] = dep[u] + 1;
		par[v] = u;
		dfs1(v);
		sz[u] += sz[v];
		if (sz[v] > sz[G[u][0]]) {
			swap(v, G[u][0]);
		}
	}
}

void dfs2(int u) {
	for (int v : G[u]) {
		if (par[u] == v) {
			continue;
		}
		top[v] = v == G[u][0] ? top[u] : v;
		dfs2(v);
	}
}

ll solve(int u, int v) {
	ll ret = dep[u] + dep[v];
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) {
			swap(u, v);
		}
		v = par[top[v]];
	}
	ret = ret - 2 * min(dep[u], dep[v]) + 1;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, T{};
	cin >> N >> M >> T;
	G.resize(N * M);
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < M; ++j) {
			int x{};
			cin >> x;
			if (x == 0) {
				int u = i * M + j;
				int v = u + M;
				G[u].push_back(v);
				G[v].push_back(u);
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M - 1; ++j) {
			int x{};
			cin >> x;
			if (x == 0) {
				int u = i * M + j;
				int v = u + 1;
				G[u].push_back(v);
				G[v].push_back(u);
			}
		}
	}
	sz.resize(N * M);
	dep.resize(N * M);
	par.resize(N * M);
	top.resize(N * M);
	par[0] = -1;
	dfs1(0);
	dfs2(0);
	vector<ll> A(T + 2);
	int K{};
	cin >> K;
	while (K--) {
		int S{}, E{}, a{}, b{}, c{}, d{}, V{};
		cin >> S >> E >> a >> b >> c >> d >> V;
		ll val = solve(a * M + b, c * M + d) * V;
		A[S] += val;
		A[E + 1] -= val;
	}
	partial_sum(A.begin(), A.end(), A.begin());
	for (int i = 1; i <= T; ++i) {
		cout << A[i] << "\n";
	}
	return 0;
}
