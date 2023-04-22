#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> G(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(N + 1);
	for (int i = 0; i < N; ++i) {
		B[A[i]] = i + 1;
	}
	vector<int> par(N + 1, -1);
	queue<int> q;
	par[1] = 0;
	q.push(1);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int y : G[x]) {
			if (par[y] == -1) {
				par[y] = x;
				q.push(y);
			}
		}
	}
	bool yes = A[0] == 1;
	for (int i = 0; i < N - 1; ++i) {
		yes &= B[par[A[i]]] <= B[par[A[i + 1]]];
	}
	cout << yes << "\n";
	return 0;
}
