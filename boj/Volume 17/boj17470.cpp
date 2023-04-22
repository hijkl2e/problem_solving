#include <bits/stdc++.h>

using namespace std;

const int dx[4]{0, 0, 1, 1};
const int dy[4]{0, 1, 0, 1};

int N, M;
vector<vector<int>> A;

void op1() {
	reverse(A.begin(), A.begin() + N / 2);
	reverse(A.begin() + N / 2, A.end());
}

void op2() {
	for (int i = 0; i < N; ++i) {
		reverse(A[i].begin(), A[i].begin() + M / 2);
		reverse(A[i].begin() + M / 2, A[i].end());
	}
}

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

void op5(vector<int> &C) {
	vector<vector<int>> B(N, vector<int>(M));
	int n = N / 2, m = M / 2;
	for (int k = 0; k < 4; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				B[i + n * dx[k]][j + m * dy[k]] = A[i + n * dx[C[k]]][j + m * dy[C[k]]];
			}
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
	vector<int> B{0, 1, 2, 3};
	bool r1{}, r2{};
	int d{};
	while (R--) {
		int q{};
		cin >> q;
		if (q == 1 || q == 2) {
			if ((q == 1) ^ (d % 2)) {
				r1 ^= true;
				rotate(B.begin(), B.begin() + 2, B.end());
			} else {
				r2 ^= true;
				swap(B[0], B[1]);
				swap(B[2], B[3]);
			}
		} else if (q == 3 || q == 4) {
			d = (d + (q == 3 ? 1 : 3)) % 4;
		} else {
			if (q == 5) {
				B = {B[2], B[0], B[3], B[1]};
			} else {
				B = {B[1], B[3], B[0], B[2]};
			}
		}
	}
	if (r1) {
		op1();
	}
	if (r2) {
		op2();
	}
	op5(B);
	while (d--) {
		op3();
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << A[i][j] << (j == M - 1 ? "\n" : " ");
		}
	}
	return 0;
}
