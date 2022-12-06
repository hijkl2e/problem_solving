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
	int N{}, M{};
	cin >> N >> M;
	G.resize(N + 1);
	H.resize(N + 1);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		H[v].push_back(u);
	}
	scc.assign(N + 1, -1);
	for (int i = 1; i <= N; ++i) {
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
	H.assign(scc_num, {});
	for (int u = 1; u <= N; ++u) {
		for (int v : G[u]) {
			if (scc[u] == scc[v]) {
				continue;
			}
			H[scc[u]].push_back(scc[v]);
		}
	}
	vector<int> ind(scc_num);
	for (int u = 0; u < scc_num; ++u) {
		for (int v : H[u]) {
			++ind[v];
		}
	}
	int X{};
	queue<int> q;
	for (int u = 0; u < scc_num; ++u) {
		if (ind[u] == 0) {
			q.push(u);
			X = u;
		}
	}
	while (q.size()) {
		if (q.size() > 1) {
			cout << "0\n";
			return 0;
		}
		int u = q.front(); q.pop();
		for (int v : H[u]) {
			if (--ind[v] == 0) {
				q.push(v);
			}
		}
	}
	vector<int> ans;
	for (int i = 1; i <= N; ++i) {
		if (scc[i] == X) {
			ans.push_back(i);
		}
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
	}
	return 0;
}
