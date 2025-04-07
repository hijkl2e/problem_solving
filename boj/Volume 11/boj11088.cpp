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
	int N{};
	cin >> N;
	cin.ignore();
	vector<vector<string>> A(N);
	for (int i = 0; i < N; ++i) {
		string s;
		getline(cin, s);
		istringstream iss(s);
		iss >> s;
		while (iss >> s) {
			A[i].push_back(s);
		}
	}
	G.resize(N);
	H.resize(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i == j) {
				continue;
			}
			if (find(A[j].begin(), A[j].end(), A[i][0]) != A[j].end()) {
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
	vector<int> B(scc_num);
	for (int i = 0; i < N; ++i) {
		++B[scc[i]];
	}
	int ans = N - *max_element(B.begin(), B.end());
	cout << ans << "\n";
	return 0;
}
