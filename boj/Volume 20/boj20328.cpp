#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> A, B;

void op1(int l) {
	int n = 1 << l;
	for (int i = 0; i < N; i += n) {
		for (int j = 0; j < n / 2; ++j) {
			swap(A[i + j], A[i + j + n / 2]);
		}
	}
}

void op2(int l) {
	int n = 1 << l;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; j += n) {
			for (int k = 0; k < n / 2; ++k) {
				swap(A[i][j + k], A[i][j + k + n / 2]);
			}
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
	deque<bool> C(n + 1);
	deque<bool> D(n + 1);
	vector<int> E(n + 1);
	while (R--) {
		int k{}, l{};
		cin >> k >> l;
		int s = k > 4 ? l + 1 : 0;
		int e = k > 4 ? n : l;
		E[n] = (E[n] + (k == 7 ? 1 : k == 8 ? 3 : 0)) % 4;
		E[l] = (E[l] + (k == 3 || k == 8 ? 1 : k == 4 || k == 7 ? 3 : 0)) % 4;
		k = (k - 1) % 4 + 1;
		for (int i = s; i <= e; ++i) {
			if (k == 1) {
				C[i] ^= true;
			} else if (k == 2) {
				D[i] ^= true;
			} else {
				swap(C[i], D[i]);
			}
		}
	}
	for (int i = 0; i <= n; ++i) {
		while (E[i]--) {
			op3(i);
		}
	}
	for (int i = 0; i <= n; ++i) {
		if (C[i]) {
			op1(i);
		}
		if (D[i]) {
			op2(i);
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << A[i][j] << (j == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
