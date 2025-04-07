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
	int N{}, M{};
	cin >> N >> M;
	G.resize(2 * N);
	H.resize(2 * N);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		u = 2 * (abs(u) - 1) + (u < 0);
		v = 2 * (abs(v) - 1) + (v < 0);
		add_edge(u, v);
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
	deque<bool> x(N);
	bool yes = true;
	for (int i = 0; i < N; ++i) {
		if (scc[2 * i] == scc[2 * i + 1]) {
			yes = false;
			break;
		}
		x[i] = scc[2 * i] > scc[2 * i + 1];
	}
	if (yes) {
		cout << "1\n";
		for (int i = 0; i < N; ++i) {
			cout << x[i] << (i == N - 1 ? "\n" : " ");
		}
	} else {
		cout << "0\n";
	}
	return 0;
}
