#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int k = 0; k < K; ++k) {
			for (int j = 0; j < N; ++j) {
				for (int l = 0; l < K; ++l) {
					cout << A[i][j] << (j == N - 1 && l == K - 1 ? "\n" : " ");
				}
			}
		}
	}
	return 0;
}
