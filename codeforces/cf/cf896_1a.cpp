#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		vector<vector<int>> A(N, vector<int>(M));
		for (int i = 0; i < N && i < M - 1; ++i) {
			for (int j = 0; j < M; ++j) {
				A[i][j] = (i + j) % M;
			}
		}
		for (int i = M - 1; i < N; ++i) {
			A[i] = A[0];
		}
		cout << (M == 1 ? 0 : min(N + 1, M)) << "\n";
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cout << A[i][j] << (j == M - 1 ? "\n" : " ");
			}
		}
	}
	return 0;
}
