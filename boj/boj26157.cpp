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
	deque<bool> A(scc_num);
	for (int u = 1; u <= N; ++u) {
		for (int v : G[u]) {
			if (scc[u] + 1 == scc[v]) {
				A[scc[v]] = true;
			}
		}
	}
	if (accumulate(A.begin(), A.end(), 0) < scc_num - 1) {
		cout << "0\n";
		return 0;
	}
	vector<int> ans;
	for (int i = 1; i <= N; ++i) {
		if (scc[i] == 0) {
			ans.push_back(i);
		}
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
	}
	return 0;
}
