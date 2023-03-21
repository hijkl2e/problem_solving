#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> G(N + 1);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
	}
	vector<int> ind(N + 1);
	for (int i = 1; i <= N; ++i) {
		for (int x : G[i]) {
			++ind[x];
		}
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= N; ++i) {
		if (ind[i] == 0) {
			pq.push(i);
		}
	}
	vector<int> A;
	while (pq.size()) {
		int x = pq.top(); pq.pop();
		for (int y : G[x]) {
			if (--ind[y] == 0) {
				pq.push(y);
			}
		}
		A.push_back(x);
	}
	for (int i = 0; i < N; ++i) {
		cout << A[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
