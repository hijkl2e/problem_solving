#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{}, X{};
	cin >> N >> M >> K >> X;
	vector<vector<int>> G(N + 1);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
	}
	vector<int> D(N + 1, -1);
	queue<int> q;
	D[X] = 0;
	q.push(X);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int y : G[x]) {
			if (D[y] == -1) {
				D[y] = D[x] + 1;
				q.push(y);
			}
		}
	}
	vector<int> A;
	for (int i = 1; i <= N; ++i) {
		if (D[i] == K) {
			A.push_back(i);
		}
	}
	if (A.size()) {
		for (int x : A) {
			cout << x << "\n";
		}
	} else {
		cout << "-1\n";
	}
	return 0;
}
