#include <bits/stdc++.h>

using namespace std;

int N, K;
string S;
vector<string> A;
deque<bool> B;
vector<vector<int>> G;

void solve(int n) {
	if (n == K - 1) {
		A.push_back(S);
		return;
	}
	for (int i = 0; i < N; ++i) {
		if (B[i]) {
			continue;
		}
		B[i] = true;
		S[n] = 'A' + i;
		solve(n + 1);
		B[i] = false;
	}
}

vector<int> hierholzer(int s) {
	vector<int> ret;
	vector<int> idx(G.size());
	stack<int> st;
	st.push(s);
	while (st.size()) {
		int u = st.top();
		if (idx[u] == G[u].size()) {
			ret.push_back(u);
			st.pop();
		} else {
			st.push(G[u][idx[u]++]);
		}
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K;
	if (N == K) {
		cout << "NO\n";
		return 0;
	}
	S = string(K - 1, 'X');
	B.resize(N);
	solve(0);
	int n = A.size();
	G.resize(n);
	for (int i = 0; i < n; ++i) {
		fill(B.begin(), B.end(), false);
		for (char c : A[i]) {
			B[c - 'A'] = true;
		}
		string s = A[i] + 'X';
		for (int j = 0; j < N; ++j) {
			if (B[j]) {
				continue;
			}
			s.back() = 'A' + j;
			int x = lower_bound(A.begin(), A.end(), s.substr(1)) - A.begin();
			G[i].push_back(x);
		}
	}
	vector<int> C = hierholzer(0);
	cout << "YES\n";
	for (int i = 0; i < C.size() - 1; ++i) {
		cout << A[C[i]] << A[C[i + 1]].back() << (i == C.size() - 2 ? "\n" : " ");
	}
	return 0;
}
