#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> par;

int bfs(int s) {
	fill(par.begin(), par.end(), -1);
	queue<int> q;
	par[s] = s;
	q.push(s);
	int x{};
	while (q.size()) {
		x = q.front(); q.pop();
		for (int y : G[x]) {
			if (par[y] == -1) {
				par[y] = x;
				q.push(y);
			}
		}
	}
	return x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	par.resize(N + 1);
	int u = bfs(1);
	int v = bfs(u);
	vector<int> A;
	deque<bool> B(N + 1);
	A.push_back(v);
	B[v] = true;
	while (u != v) {
		v = par[v];
		A.push_back(v);
		B[v] = true;
	}
	vector<int> C;
	for (int i = 0; i < A.size(); ++i) {
		if (i % 2 == 0) {
			C.push_back(A[i]);
			continue;
		}
		for (int x : G[A[i]]) {
			if (!B[x]) {
				C.push_back(x);
			}
		}
	}
	for (int i = A.size() - 1; i >= 0; --i) {
		if (i % 2) {
			C.push_back(A[i]);
			continue;
		}
		for (int x : G[A[i]]) {
			if (!B[x]) {
				C.push_back(x);
			}
		}
	}
	if (C.size() == N) {
		cout << "Yes\n";
		for (int i = 0; i < N; ++i) {
			cout << C[i] << (i == N - 1 ? "\n" : " ");
		}
	} else {
		cout << "No\n";
	}
	return 0;
}
