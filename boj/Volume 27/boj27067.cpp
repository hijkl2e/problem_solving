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
	sort(A[0].begin(), A[0].end(), [&](int a, int b) {
		return B[a][b] > 1;
	});
	for (int i = 0; i < N; ++i) {
		cout << A[0][i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
