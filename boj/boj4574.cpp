#include <bits/stdc++.h>

using namespace std;

int A[9][9];
bool row[9][10];
bool col[9][10];
bool square[9][10];
bool domino[10][10];

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
		for (int j = 1; j < 10; ++j) {
			if (i == j || domino[i][j]) {
				continue;
			}
			domino[i][j] = domino[j][i] = true;
			int nz = x / 3 * 3 + (y + 1) / 3 % 3;
			if (y < 8 && A[x][y + 1] == 0 && !(row[x][j] || col[y + 1][j] || square[nz][j])) {
				A[x][y + 1] = j;
				row[x][j] = col[y + 1][j] = square[nz][j] = true;
				if (solve(step + 1)) {
					return true;
				}
				row[x][j] = col[y + 1][j] = square[nz][j] = false;
				A[x][y + 1] = 0;
			}
			nz = (x + 1) / 3 * 3 + y / 3 % 3;
			if (x < 8 && A[x + 1][y] == 0 && !(row[x + 1][j] || col[y][j] || square[nz][j])) {
				A[x + 1][y] = j;
				row[x + 1][j] = col[y][j] = square[nz][j] = true;
				if (solve(step + 1)) {
					return true;
				}
				row[x + 1][j] = col[y][j] = square[nz][j] = false;
				A[x + 1][y] = 0;
			}
			domino[i][j] = domino[j][i] = false;
		}
		row[x][i] = col[y][i] = square[z][i] = false;
	}
	A[x][y] = 0;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	for (int tc = 1; cin >> N, N; ++tc) {
		memset(A, 0, sizeof A);
		memset(row, 0, sizeof row);
		memset(col, 0, sizeof col);
		memset(square, 0, sizeof square);
		memset(domino, 0, sizeof domino);
		while (N--) {
			int u{}, v{};
			string lu, lv;
			cin >> u >> lu >> v >> lv;
			A[lu[0] - 'A'][lu[1] - '1'] = u;
			A[lv[0] - 'A'][lv[1] - '1'] = v;
			domino[u][v] = domino[v][u] = true;
		}
		for (int i = 1; i < 10; ++i) {
			string l;
			cin >> l;
			A[l[0] - 'A'][l[1] - '1'] = i;
		}
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				int x = A[i][j];
				row[i][x] = col[j][x] = square[i / 3 * 3 + j / 3 % 3][x] = true;
			}
		}
		cout << "Puzzle " << tc << "\n";
		solve(0);
	}
	return 0;
}
