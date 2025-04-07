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
	int K{}, N{};
	cin >> K >> N;
	G.resize(2 * K);
	H.resize(2 * K);
	vector<int> A(3);
	while (N--) {
		for (int i = 0; i < 3; ++i) {
			char c{};
			cin >> A[i] >> c;
			A[i] = 2 * (A[i] - 1) + (c == 'B');
		}
		for (int i = 0; i < 3; ++i) {
			add_edge(A[i], A[(i + 1) % 3]);
		}
	}
	scc.assign(2 * K, -1);
	for (int i = 0; i < 2 * K; ++i) {
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
	deque<bool> x(K);
	bool yes = true;
	for (int i = 0; i < K; ++i) {
		if (scc[2 * i] == scc[2 * i + 1]) {
			yes = false;
			break;
		}
		x[i] = scc[2 * i] > scc[2 * i + 1];
	}
	if (yes) {
		for (int i = 0; i < K; ++i) {
			cout << (x[i] ? "R" : "B");
		}
		cout << "\n";
	} else {
		cout << "-1\n";
	}
	return 0;
}
