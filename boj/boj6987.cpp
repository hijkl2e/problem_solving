#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> A;
vector<int> B, C;

bool solve(int n) {
	if (n == 15) {
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (A[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
	int x = B[n], y = C[n];
	for (int i = 0; i < 3; ++i) {
		int j = 2 - i;
		if (A[x][i] && A[y][j]) {
			--A[x][i], --A[y][j];
			if (solve(n + 1)) {
				return true;
			}
			++A[x][i], ++A[y][j];
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 4;
	A.assign(6, vector<int>(3));
	for (int i = 0; i < 6; ++i) {
		for (int j = i + 1; j < 6; ++j) {
			B.push_back(i);
			C.push_back(j);
		}
	}
	while (T--) {
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 3; ++j) {
				cin >> A[i][j];
			}
		}
		cout << solve(0) << (T ? " " : "\n");
	}
	return 0;
}
