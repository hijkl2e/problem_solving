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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		int N{}, M{};
		cin >> N >> M;
		G.assign(N, {});
		H.assign(N, {});
		while (M--) {
			int u{}, v{};
			cin >> u >> v;
			G[u].push_back(v);
			H[v].push_back(u);
		}
		scc.assign(N, -1);
		for (int i = 0; i < N; ++i) {
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
		vector<int> ind(scc_num);
		for (int u = 0; u < N; ++u) {
			for (int v : G[u]) {
				if (scc[u] == scc[v]) {
					continue;
				}
				++ind[scc[v]];
			}
		}
		if (tc) {
			cout << "\n";
		}
		if (count(ind.begin(), ind.end(), 0) == 1) {
			for (int i = 0; i < N; ++i) {
				if (scc[i] == 0) {
					cout << i << "\n";
				}
			}
		} else {
			cout << "Confused\n";
		}
	}
	return 0;
}
