#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(M));
	for (int k = 0; k < 2; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				int x{};
				cin >> x;
				A[i][j] += x;
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << A[i][j] << (j == M - 1 ? "\n" : " ");
		}
	}
	return 0;
}
