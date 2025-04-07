#include <bits/stdc++.h>

using namespace std;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

vector<vector<int>> A(5, vector<int>(5));

bool solve(int z, int r, int c, int a) {
	if (a == 2) {
		return true;
	} else if (z == 3) {
		return false;
	}
	for (int i = 0; i < 4; ++i) {
		int nx = r + dx[i];
		int ny = c + dy[i];
		if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && A[nx][ny] > -1) {
			int t = A[nx][ny];
			A[nx][ny] = -1;
			if (solve(z + 1, nx, ny, a + t)) {
				return true;
			}
			A[nx][ny] = t;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> A[i][j];
		}
	}
	int r{}, c{};
	cin >> r >> c;
	A[r][c] = -1;
	cout << solve(0, r, c, 0) << "\n";
	return 0;
}
