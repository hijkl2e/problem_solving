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
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		G.assign(N + 1, {});
		H.assign(N + 1, {});
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
		if (scc_num == 1) {
			cout << "0\n";
			continue;
		}
		deque<bool> A(scc_num, true);
		deque<bool> B(scc_num, true);
		for (int u = 1; u <= N; ++u) {
			for (int v : G[u]) {
				if (scc[u] == scc[v]) {
					continue;
				}
				A[scc[u]] = false;
				B[scc[v]] = false;
			}
		}
		int ans = max(accumulate(A.begin(), A.end(), 0), accumulate(B.begin(), B.end(), 0));
		cout << ans << "\n";
	}
	return 0;
}
