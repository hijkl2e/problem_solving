#include <bits/stdc++.h>

using namespace std;

class UF {
public:
	UF(int N) : par(N), sz(N, 1) {
		for (int i = 0; i < N; ++i) {
			par[i] = i;
		}
	}
	int root(int x) {
		return par[x] == x ? x : (par[x] = root(par[x]));
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	bool unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) {
			return false;
		}
		if (sz[x] < sz[y]) {
			swap(x, y);
		}
		par[y] = x;
		sz[x] += sz[y];
		return true;
	}
	int size(int x) {
		return sz[root(x)];
	}
private:
	vector<int> par, sz;
};

vector<vector<int>> G, H;
stack<int> st;
vector<int> scc;

void dfs(int x, int scc_num) {
	scc[x] = scc_num == -1 ? 0 : scc_num;
	for (int y : scc_num == -1 ? G[x] : H[x]) {
		if (scc[y] == -1) {
			dfs(y, scc_num);
		}
	}
	if (scc_num == -1) {
		st.push(x);
	}
}

void add_edge(int u, int v) {
	G[u ^ 1].push_back(v);
	G[v ^ 1].push_back(u);
	H[v].push_back(u ^ 1);
	H[u].push_back(v ^ 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, A{}, B{};
	cin >> N >> A >> B;
	G.resize(4 * N);
	H.resize(4 * N);
	while (A--) {
		int u{}, v{};
		cin >> u >> v;
		u = 4 * (u - 1);
		v = 4 * (v - 1);
		add_edge(u, v);
	}
	UF uf(N);
	while (B--) {
		int u{}, v{};
		cin >> u >> v;
		uf.unite(u - 1, v - 1);
	}
	vector<vector<int>> C(N);
	for (int i = 0; i < N; ++i) {
		C[uf.root(i)].push_back(i);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j < C[i].size(); ++j) {
			int u = C[i][j - 1];
			int v = C[i][j];
			add_edge(4 * u + 1, 4 * u + 2);
			add_edge(4 * u + 3, 4 * v + 2);
			add_edge(4 * u + 3, 4 * v + 1);
		}
	}
	scc.assign(4 * N, -1);
	for (int i = 0; i < 4 * N; ++i) {
		if (scc[i] == -1) {
			dfs(i, -1);
		}
	}
	fill(scc.begin(), scc.end(), -1);
	int scc_num{};
	while (st.size()) {
		int x = st.top(); st.pop();
		if (scc[x] == -1) {
			dfs(x, scc_num++);
		}
	}
	vector<int> F;
	bool yes = true;
	for (int i = 0; i < N; ++i) {
		if (scc[4 * i] == scc[4 * i + 1]) {
			yes = false;
			break;
		} else if (scc[4 * i] > scc[4 * i + 1]) {
			F.push_back(i + 1);
		}
	}
	if (yes) {
		cout << "YES\n";
		for (int i = 0; i < F.size(); ++i) {
			cout << F[i] << (i == F.size() - 1 ? "" : " ");
		}
		cout << "\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}
