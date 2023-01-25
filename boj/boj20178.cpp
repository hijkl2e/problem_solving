#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> A;

bool solve() {
	for (int i = 0; i < N; ++i) {
		int x = -1;
		for (int j = i; j < N; ++j) {
			if (A[j][i]) {
				x = j;
				break;
			}
		}
		if (x == -1) {
			return false;
		}
		swap(A[i], A[x]);
		for (int j = i + 1; j < N; ++j) {
			if (A[j][i] == 0) {
				continue;
			}
			for (int k = i; k < 2 * N; ++k) {
				A[j][k] ^= A[i][k];
			}
		}
	}
	for (int i = N - 1; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (A[j][i] == 0) {
				continue;
			}
			for (int k = i; k < 2 * N; ++k) {
				A[j][k] ^= A[i][k];
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.assign(N, vector<int>(2 * N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
		A[i][N + i] = 1;
	}
	if (solve()) {
		for (int i = 0; i < N; ++i) {
			vector<int> B;
			for (int j = 0; j < N; ++j) {
				if (A[i][N + j]) {
					B.push_back(j + 1);
				}
			}
			for (int j = 0; j < B.size(); ++j) {
				cout << B[j] << (j == B.size() - 1 ? "\n" : " ");
			}
		}
	} else {
		cout << "-1\n";
	}
	return 0;
}
