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
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	cin.ignore();
	G.resize(N);
	H.resize(N);
	for (int i = 0; i < N; ++i) {
		string s;
		getline(cin, s);
		for (int j = 0; j < N; ++j) {
			if (s[j] == '1') {
				G[i].push_back(j);
				H[j].push_back(i);
			}
		}
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
	vector<int> B(scc_num, INF);
	for (int i = 0; i < N; ++i) {
		B[scc[i]] = min(B[scc[i]], A[i]);
	}
	int ans = accumulate(B.begin(), B.end(), 0);
	cout << ans << "\n";
	return 0;
}
