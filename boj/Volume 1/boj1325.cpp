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
		G[v].push_back(u);
		H[u].push_back(v);
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
	vector<int> ind(scc_num);
	for (int u = 1; u <= N; ++u) {
		for (int v : G[u]) {
			if (scc[u] == scc[v]) {
				continue;
			}
			H[scc[u]].push_back(scc[v]);
			++ind[scc[v]];
		}
	}
	vector<vector<int>> S(scc_num);
	for (int i = 1; i <= N; ++i) {
		S[scc[i]].push_back(i);
	}
	vector<bitset<10001>> B(scc_num);
	for (int u = scc_num - 1; u >= 0; --u) {
		queue<int> q;
		B[u][u] = true;
		q.push(u);
		for (int v : H[u]) {
			if (B[u][v]) {
				continue;
			}
			B[u] |= B[v];
		}
	}
	vector<int> A;
	int now{};
	for (int i = 0; i < scc_num; ++i) {
		if (ind[i]) {
			continue;
		}
		int cnt{};
		for (int j = 0; j < scc_num; ++j) {
			if (B[i][j]) {
				cnt += S[j].size();
			}
		}
		if (now < cnt) {
			A.clear();
			A.push_back(i);
			now = cnt;
		} else if (now == cnt) {
			A.push_back(i);
		}
	}
	vector<int> C;
	for (int x : A) {
		copy(S[x].begin(), S[x].end(), back_inserter(C));
	}
	sort(C.begin(), C.end());
	for (int i = 0; i < C.size(); ++i) {
		cout << C[i] << (i == C.size() - 1 ? "\n" : " ");
	}
	return 0;
}
