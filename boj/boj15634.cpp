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
	for (int i = 1; i < N; i += 2) {
		reverse(A[i].begin(), A[i].end());
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << (i && j == 0 ? "D" : i % 2 ? "L" : "R");
			if (A[i][j] == '.') {
				cout << (i % 2 ? "LR" : "RL");
				if (j + 1 < M) {
					A[i][j + 1] = A[i][j + 1] == '#' ? '.' : '#';
				}
			}
		}
	}
	cout << "\n";
	return 0;
}
