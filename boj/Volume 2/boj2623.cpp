#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> G(N + 1);
	while (M--) {
		int K{}, x{};
		cin >> K >> x;
		while (--K) {
			int y{};
			cin >> y;
			G[x].push_back(y);
			x = y;
		}
	}
	vector<int> ind(N + 1);
	for (int u = 1; u <= N; ++u) {
		for (int v : G[u]) {
			++ind[v];
		}
	}
	queue<int> q;
	for (int i = 1; i <= N; ++i) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}
	vector<int> A;
	while (q.size()) {
		int x = q.front(); q.pop();
		A.push_back(x);
		for (int y : G[x]) {
			if (--ind[y] == 0) {
				q.push(y);
			}
		}
	}
	if (A.size() == N) {
		for (int x : A) {
			cout << x << "\n";
		}
	} else {
		cout << "0\n";
	}
	return 0;
}
