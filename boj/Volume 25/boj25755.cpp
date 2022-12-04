#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	char W{};
	int N{};
	cin >> W >> N;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	vector<int> B{-1, 1, 5, -1, -1, 2, -1, -1, 8, -1};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			A[i][j] = B[A[i][j]];
		}
	}
	if (W == 'L' || W == 'R') {
		for (int i = 0; i < N; ++i) {
			for (int j = 0, k = N - 1; j < k; ++j, --k) {
				swap(A[i][j], A[i][k]);
			}
		}
	} else {
		for (int i = 0; i < N; ++i) {
			for (int j = 0, k = N - 1; j < k; ++j, --k) {
				swap(A[j][i], A[k][i]);
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] == -1) {
				cout << "?";
			} else {
				cout << A[i][j];
			}
			cout << (j == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
