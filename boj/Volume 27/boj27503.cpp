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
	int N{}, M{}, C{}, K{};
	cin >> N >> M >> C >> K;
	G.resize(2 * N);
	H.resize(2 * N);
	deque<bool> A(N + 1);
	while (M--) {
		int x{};
		cin >> x;
		A[x] = true;
	}
	while (C--) {
		int u{}, v{};
		cin >> u >> v;
		A[u] = A[v] = false;
		add_edge(2 * (u - 1), 2 * (v - 1));
	}
	for (int i = 1; i <= N; ++i) {
		if (A[i]) {
			add_edge(2 * (i - 1), 2 * (i - 1));
		}
	}
	while (K--) {
		int u{}, v{};
		cin >> u >> v;
		add_edge(2 * u - 1, 2 * v - 1);
	}
	scc.assign(2 * N, -1);
	for (int i = 0; i < 2 * N; ++i) {
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
	cout << (yes ? "YES" : "NO") << "\n";
	return 0;
}
