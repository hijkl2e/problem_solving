#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

vector<vector<ii>> G;
vector<int> ind, c;
vector<ll> ans_x;
deque<bool> vst;

void dfs1(int u) {
	for (auto &[v, w] : G[u]) {
		if (c[v] == -1) {
			c[v] = c[u];
			dfs1(v);
		}
	}
}

void dfs2(int u) {
	for (auto &[v, w] : G[u]) {
		if (ind[v] && ans_x[v] == 0) {
			ans_x[v] = ans_x[u] + w;
			dfs2(v);
		}
	}
}

void dfs3(int u) {
	for (auto &[v, w] : G[u]) {
		if (ind[v] == 0) {
			ans_x[v] = ans_x[u] + (ans_x[u] || vst[u] ? w : 0);
			dfs3(v);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> X(N + 1);
	vector<int> D(N + 1);
	G.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> X[i] >> D[i];
		G[X[i]].push_back({i, D[i]});
	}
	vector<int> R(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> R[i];
	}
	ind.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		++ind[X[i]];
	}
	queue<int> q;
	for (int i = 1; i <= N; ++i) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}
	while (q.size()) {
		int u = q.front(); q.pop();
		if (--ind[X[u]] == 0) {
			q.push(X[u]);
		}
	}
	c.resize(N + 1, -1);
	int cn{};
	for (int i = 1; i <= N; ++i) {
		if (ind[i] && c[i] == -1) {
			c[i] = cn++;
			dfs1(i);
		}
	}
	vector<ll> len(cn);
	vst.resize(N + 1);
	vector<int> sp(cn, -1);
	vector<int> pp(cn, -1);
	ans_x.resize(N + 1);
	vector<ll> ans_c(cn);
	int M{};
	cin >> M;
	while (M--) {
		int u{};
		cin >> u;
		vst[u] = true;
		if (ind[u] == 0 || pp[c[u]] == u) {
			continue;
		}
		if (sp[c[u]] == -1) {
			dfs2(u);
			len[c[u]] = ans_x[u];
			ans_x[u] = 0;
			sp[c[u]] = pp[c[u]] = u;
		}
		ans_c[c[u]] += (ans_x[pp[c[u]]] - ans_x[u] + len[c[u]]) % len[c[u]];
		pp[c[u]] = u;
	}
	for (int i = 1; i <= N; ++i) {
		if (ind[i]) {
			dfs3(i);
		}
	}
	for (int i = 1; i <= N; ++i) {
		cout << R[i] * (ans_x[i] + ans_c[c[i]]) << "\n";
	}
	return 0;
}
