#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

vector<vector<int>> A(5, vector<int>(5));

bool end(int r1, int c1, int r2, int c2) {
	for (int k = 0; k < 2; ++k) {
		for (int i = 0; i < 4; ++i) {
			int nx = r1 + dx[i];
			int ny = c1 + dy[i];
			if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && A[nx][ny] > -1) {
				return false;
			}
		}
		swap(r1, r2);
		swap(c1, c2);
	}
	return true;
}

bool solve(int z, int r1, int c1, int a1, int r2, int c2, int a2) {
	if (end(r1, c1, r2, c2)) {
		return a1 > a2;
	}
	int r = z ? r1 : r2;
	int c = z ? c1 : c2;
	bool flag = true;
	for (int i = 0; i < 4; ++i) {
		int nx = r + dx[i];
		int ny = c + dy[i];
		if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && A[nx][ny] > -1) {
			int t = A[nx][ny];
			A[nx][ny] = -1;
			bool res{};
			if (z) {
				res = solve(z ^ 1, nx, ny, a1 + t, r2, c2, a2);
			} else {
				res = solve(z ^ 1, r1, c1, a1, nx, ny, a2 + t);
			}
			A[nx][ny] = t;
			if (z == res) {
				return z;
			}
			flag = false;
		}
	}
	return flag ? solve(z ^ 1, r1, c1, a1, r2, c2, a2) : !z;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> A[i][j];
		}
	}
	int r1{}, c1{}, r2{}, c2{};
	cin >> r1 >> c1 >> r2 >> c2;
	A[r1][c1] = A[r2][c2] = -1;
	cout << solve(1, r1, c1, 0, r2, c2, 0) << "\n";
	return 0;
}
