#include <bits/stdc++.h>

using namespace std;

const int dx[4]{0, 1, -1, 0};
const int dy[4]{1, 0, 0, -1};

int N, M;
vector<vector<int>> A;

void op3() {
	vector<vector<int>> B(M, vector<int>(N));
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			B[i][j] = A[N - j - 1][i];
		}
	}
	swap(A, B);
	swap(N, M);
}

void op5() {
	vector<vector<int>> B(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int d = i / (N / 2) * 2 + j / (M / 2);
			B[i + N / 2 * dx[d]][j + M / 2 * dy[d]] = A[i][j];
		}
	}
	swap(A, B);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{};
	cin >> N >> M >> R;
	A.assign(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	while (R--) {
		int q{};
		cin >> q;
		if (q == 1) {
			reverse(A.begin(), A.end());
		} else if (q == 2) {
			for (int i = 0; i < N; ++i) {
				reverse(A[i].begin(), A[i].end());
			}
		} else if (q == 3 || q == 4) {
			for (int i = q == 4 ? 3 : 1; i > 0; --i) {
				op3();
			}
		} else {
			for (int i = q == 6 ? 3 : 1; i > 0; --i) {
				op5();
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
