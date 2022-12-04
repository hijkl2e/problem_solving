#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> G(N + 1);
	for (int i = 0; i < 5; ++i) {
		int P{};
		cin >> P;
		while (P--) {
			int K{}, L{};
			cin >> K >> L;
			G[K].push_back(L);
			G[L].push_back(K);
		}
	}
	vector<int> A(N + 1);
	vector<int> B(N + 1);
	deque<bool> inq(N + 1);
	queue<int> q;
	for (int i = 1; i <= N; ++i) {
		B[i] = G[i].size();
		if (B[i] > 2) {
			inq[i] = true;
			q.push(i);
		}
	}
	while (q.size()) {
		int x = q.front(); q.pop();
		inq[x] = false;
		if (B[x] <= 2) {
			continue;
		}
		A[x] = 1 - A[x];
		B[x] = G[x].size() - B[x];
		for (int y : G[x]) {
			if (A[x] == A[y]) {
				if (++B[y] > 2 && !inq[y]) {
					inq[y] = true;
					q.push(y);
				}
			} else {
				--B[y];
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		char c = 'A' + (A[i] ^ A[1]);
		cout << c;
	}
	cout << "\n";
	return 0;
}
