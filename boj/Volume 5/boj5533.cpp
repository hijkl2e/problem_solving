#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(3, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> A[j][i];
		}
	}
	vector<int> B(101);
	vector<int> C(N);
	for (int i = 0; i < 3; ++i) {
		fill(B.begin(), B.end(), 0);
		for (int j = 0; j < N; ++j) {
			++B[A[i][j]];
		}
		for (int j = 0; j < N; ++j) {
			if (B[A[i][j]] == 1) {
				C[j] += A[i][j];
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << C[i] << "\n";
	}
	return 0;
}
