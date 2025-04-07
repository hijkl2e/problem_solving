#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{}, M{};
	cin >> N >> K >> M;
	vector<vector<int>> G(N + M + 1);
	for (int i = 1; i <= M; ++i) {
		for (int j = 0; j < K; ++j) {
			int x{};
			cin >> x;
			G[x].push_back(N + i);
			G[N + i].push_back(x);
		}
	}
	vector<int> D(N + M + 1, -1);
	queue<int> q;
	D[1] = 0;
	q.push(1);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int y : G[x]) {
			if (D[y] == -1) {
				D[y] = D[x] + 1;
				q.push(y);
			}
		}
	}
	cout << (D[N] == -1 ? -1 : (D[N] / 2 + 1)) << "\n";
	return 0;
}
