#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		int M{};
		cin >> M;
		vector<deque<bool>> B(N + 1, deque<bool>(N + 1));
		while (M--) {
			int u{}, v{};
			cin >> u >> v;
			B[u][v] = B[v][u] = true;
		}
		vector<vector<int>> G(N + 1);
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				if (B[A[i]][A[j]]) {
					G[A[j]].push_back(A[i]);
				} else {
					G[A[i]].push_back(A[j]);
				}
			}
		}
		vector<int> ind(N + 1);
		for (int i = 1; i <= N; ++i) {
			for (int x : G[i]) {
				++ind[x];
			}
		}
		queue<int> q;
		for (int i = 1; i <= N; ++i) {
			if (ind[i] == 0) {
				q.push(i);
			}
		}
		vector<int> C;
		while (q.size() == 1) {
			int x = q.front(); q.pop();
			for (int y : G[x]) {
				if (--ind[y] == 0) {
					q.push(y);
				}
			}
			C.push_back(x);
		}
		if (C.size() == N) {
			for (int i = 0; i < N; ++i) {
				cout << C[i] << (i == N - 1 ? "\n" : " ");
			}
		} else {
			cout << (q.size() ? "?" : "IMPOSSIBLE") << "\n";
		}
	}
	return 0;
}
