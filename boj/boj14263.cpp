#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<int> U(123, N);
	vector<int> D(123, -1);
	vector<int> L(123, M);
	vector<int> R(123, -1);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			char c = A[i][j];
			if (c == '.') {
				continue;
			}
			U[c] = min(U[c], i);
			D[c] = max(D[c], i);
			L[c] = min(L[c], j);
			R[c] = max(R[c], j);
		}
	}
	vector<deque<bool>> G(123, deque<bool>(123));
	for (int k = 48; k < 123; ++k) {
		for (int i = U[k]; i <= D[k]; ++i) {
			for (int j = L[k]; j <= R[k]; ++j) {
				char c = A[i][j];
				if (c == '.') {
					cout << "-1\n";
					return 0;
				} else if (c == k) {
					continue;
				}
				G[k][c] = true;
			}
		}
	}
	vector<int> ind(123);
	for (int i = 48; i < 123; ++i) {
		for (int j = 48; j < 123; ++j) {
			if (G[i][j]) {
				++ind[j];
			}
		}
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 48; i < 123; ++i) {
		if (U[i] < N && ind[i] == 0) {
			pq.push(i);
		}
	}
	string ans;
	while (pq.size()) {
		char c = pq.top(); pq.pop();
		for (int i = 48; i < 123; ++i) {
			if (G[c][i] && --ind[i] == 0) {
				pq.push(i);
			}
		}
		ans += c;
	}
	if (accumulate(ind.begin(), ind.end(), 0)) {
		cout << "-1\n";
	} else {
		cout << ans << "\n";
	}
	return 0;
}
