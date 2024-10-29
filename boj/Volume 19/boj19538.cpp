#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> G(N + 1);
	for (int i = 1; i <= N; ++i) {
		int x{};
		while (cin >> x, x) {
			G[i].push_back(x);
		}
	}
	vector<int> D(N + 1, -1);
	queue<int> q;
	int M{};
	cin >> M;
	while (M--) {
		int x{};
		cin >> x;
		D[x] = 0;
		q.push(x);
	}
	vector<int> A(N + 1);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int y : G[x]) {
			if (++A[y] >= (G[y].size() + 1) / 2 && D[y] == -1) {
				D[y] = D[x] + 1;
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		cout << D[i] << (i == N ? "\n" : " ");
	}
	return 0;
}
