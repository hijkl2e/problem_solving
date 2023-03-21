#include <bits/stdc++.h>

using namespace std;

int A[9][9];
bool row[9][10];
bool col[9][10];
bool square[9][10];

bool solve(int step) {
	if (step == 81) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cout << A[i][j];
			}
			cout << "\n";
		}
		return true;
	}
	int x = step / 9;
	int y = step % 9;
	if (A[x][y]) {
		return solve(step + 1);
	}
	int z = x / 3 * 3 + y / 3 % 3;
	for (int i = 1; i < 10; ++i) {
		if (row[x][i] || col[y][i] || square[z][i]) {
			continue;
		}
		A[x][y] = i;
		row[x][i] = col[y][i] = square[z][i] = true;
		if (solve(step + 1)) {
			return true;
		}
		row[x][i] = col[y][i] = square[z][i] = false;
	}
	A[x][y] = 0;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < 9; ++i) {
		string s;
		getline(cin, s);
		for (int j = 0; j < 9; ++j) {
			A[i][j] = s[j] - '0';
		}
	}
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			int x = A[i][j];
			row[i][x] = col[j][x] = square[i / 3 * 3 + j / 3 % 3][x] = true;
		}
	}
	solve(0);
	return 0;
}
