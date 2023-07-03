#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> A;

vector<int> hierholzer(int s) {
	vector<int> ret;
	vector<int> idx(A.size());
	stack<int> st;
	st.push(s);
	while (st.size()) {
		int u = st.top();
		while (idx[u] < A[u].size() && A[u][idx[u]] == 0) {
			++idx[u];
		}
		if (idx[u] == A[u].size()) {
			ret.push_back(u);
			st.pop();
		} else {
			st.push(idx[u]);
			--A[u][idx[u]];
			--A[idx[u]][u];
		}
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	A.assign(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	bool yes = true;
	for (int i = 0; i < N; ++i) {
		if (accumulate(A[i].begin(), A[i].end(), 0) % 2) {
			yes = false;
			break;
		}
	}
	if (!yes) {
		cout << "-1\n";
		return 0;
	}
	vector<int> B = hierholzer(0);
	for (int i = 0; i < B.size(); ++i) {
		cout << B[i] + 1 << (i == B.size() - 1 ? "\n" : " ");
	}
	return 0;
}
