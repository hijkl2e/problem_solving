#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

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
	int N{}, M{}, s{}, t{};
	cin >> N >> M >> s >> t;
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
	vector<int> A(scc_num);
	for (int i = 1; i <= N; ++i) {
		++A[scc[i]];
	}
	vector<int> dp(scc_num, -INF);
	dp[scc[t]] = 0;
	for (int u = scc_num - 1; u >= 0; --u) {
		for (int v : H[u]) {
			dp[u] = max(dp[u], dp[v]);
		}
		dp[u] += A[u];
	}
	cout << max(dp[scc[s]], 0) << "\n";
	return 0;
}
