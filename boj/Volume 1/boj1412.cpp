#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<vector<int>> G(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] == 'Y' && A[j][i] == 'N') {
				G[i].push_back(j);
			}
		}
	}
	vector<int> ind(N);
	for (int i = 0; i < N; ++i) {
		for (int x : G[i]) {
			++ind[x];
		}
	}
	queue<int> q;
	for (int i = 0; i < N; ++i) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int y : G[x]) {
			if (--ind[y] == 0) {
				q.push(y);
			}
		}
	}
	cout << (count(ind.begin(), ind.end(), 0) == N ? "YES" : "NO") << "\n";
	return 0;
}
