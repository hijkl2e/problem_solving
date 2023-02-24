#include <bits/stdc++.h>

using namespace std;

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
	int N{}, M{}, A{}, B{};
	cin >> N >> M >> A >> B;
	G.resize(2 * N + A);
	H.resize(2 * N + A);
	vector<vector<int>> C(M + 1);
	while (A--) {
		int x{}, y{};
		cin >> x >> y;
		C[y].push_back(x - 1);
	}
	while (B--) {
		int u{}, v{};
		cin >> u >> v;
		u = 2 * (u - 1);
		v = 2 * (v - 1);
		add_edge(u, v);
	}
	int sz = 2 * N;
	for (int i = 1; i <= M; ++i) {
		if (C[i].size() < 10) {
			for (int j = 0; j < C[i].size(); ++j) {
				for (int k = j + 1; k < C[i].size(); ++k) {
					add_edge(2 * C[i][j] + 1, 2 * C[i][k] + 1);
				}
			}
			continue;
		}
		int z{};
		while ((1 << z) < C[i].size()) {
			++z;
		}
		for (int j = 0; j < C[i].size(); ++j) {
			for (int k = 0; k < z; ++k) {
				add_edge(2 * C[i][j] + 1, sz + 2 * k + ((j >> k) & 1));
			}
		}
		sz += 2 * z;
	}
	scc.assign(sz, -1);
	for (int i = 0; i < sz; ++i) {
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
	bool yes = true;
	for (int i = 0; i < N; ++i) {
		if (scc[2 * i] == scc[2 * i + 1]) {
			yes = false;
			break;
		}
	}
	cout << (yes ? "TAK" : "NIE") << "\n";
	return 0;
}
