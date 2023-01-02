#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(3, vector<int>(N));
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<int>> B(N + 1, vector<int>(N + 1));
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = j + 1; k < N; ++k) {
				++B[A[i][j]][A[i][k]];
			}
		}
	}
	vector<vector<int>> G(N + 1);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (B[i][j] > 1) {
				G[i].push_back(j);
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
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int y : G[x]) {
			if (--ind[y] == 0) {
				q.push(y);
			}
		}
		C.push_back(x);
	}
	for (int i = 0; i < C.size(); ++i) {
		cout << C[i] << (i == C.size() - 1 ? "\n" : " ");
	}
	return 0;
}
