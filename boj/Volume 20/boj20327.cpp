#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> A, B;

void op1(int l) {
	int n = 1 << l;
	for (int i = 0; i < N; i += n) {
		reverse(A.begin() + i, A.begin() + i + n);
	}
}

void op2(int l) {
	int n = 1 << l;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; j += n) {
			reverse(A[i].begin() + j, A[i].begin() + j + n);
		}
	}
}

void op3(int l) {
	int n = 1 << l;
	for (int i = 0; i < N; i += n) {
		for (int j = 0; j < N; j += n) {
			for (int x = 0; x < n; ++x) {
				for (int y = 0; y < n; ++y) {
					B[x][y] = A[i + n - y - 1][j + x];
				}
			}
			for (int x = 0; x < n; ++x) {
				for (int y = 0; y < n; ++y) {
					A[i + x][j + y] = B[x][y];
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n{}, R{};
	cin >> n >> R;
	N = 1 << n;
	A.assign(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	B.assign(N, vector<int>(N));
	while (R--) {
		int k{}, l{};
		cin >> k >> l;
		if (k == 1) {
			op1(l);
		} else if (k == 2) {
			op2(l);
		} else if (k == 3 || k == 4) {
			for (int i = k == 3 ? 1 : 3; i > 0; --i) {
				op3(l);
			}
		} else if (k == 5) {
			op1(n);
			op1(l);
		} else if (k == 6) {
			op2(n);
			op2(l);
		} else {
			op3(k == 7 ? n : l);
			for (int i = 0; i < 3; ++i) {
				op3(k == 7 ? l : n);
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << A[i][j] << (j == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
