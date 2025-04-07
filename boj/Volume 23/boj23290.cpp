#include <bits/stdc++.h>

using namespace std;

const int dx[8]{-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8]{0, -1, -1, -1, 0, 1, 1, 1};

int A[4][4][8];
int B[4][4][8];
int C[4][4];
int D[4][4];

bool solve(int x, int y) {
	return 0 <= x && x < 4 && 0 <= y && y < 4;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{}, S{};
	cin >> M >> S;
	while (M--) {
		int x{}, y{}, d{};
		cin >> x >> y >> d;
		++A[x - 1][y - 1][(11 - d) % 8];
	}
	int sx{}, sy{};
	cin >> sx >> sy;
	--sx, --sy;
	memset(D, 0x3f, sizeof D);
	while (S--) {
		memcpy(B, A, sizeof A);
		memset(A, 0, sizeof A);
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				for (int k = 0; k < 8; ++k) {
					int l{};
					for (; l < 8; ++l) {
						int d = (k + l) % 8;
						int nx = i + dx[d];
						int ny = j + dy[d];
						if (solve(nx, ny) && !(nx == sx && ny == sy) && D[nx][ny] > S + 2) {
							A[nx][ny][d] += B[i][j][k];
							break;
						}
					}
					if (l == 8) {
						A[i][j][k] += B[i][j][k];
					}
				}
			}
		}
		memset(C, 0, sizeof C);
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				for (int k = 0; k < 8; ++k) {
					C[i][j] += A[i][j][k];
				}
			}
		}
		int z{}, cnt = -1;
		for (int i = 0; i < 8; i += 2) {
			int x1 = sx + dx[i];
			int y1 = sy + dy[i];
			if (!solve(x1, y1)) {
				continue;
			}
			int c1 = C[x1][y1];
			C[x1][y1] = 0;
			for (int j = 0; j < 8; j += 2) {
				int x2 = x1 + dx[j];
				int y2 = y1 + dy[j];
				if (!solve(x2, y2)) {
					continue;
				}
				int c2 = C[x2][y2];
				C[x2][y2] = 0;
				for (int k = 0; k < 8; k += 2) {
					int x3 = x2 + dx[k];
					int y3 = y2 + dy[k];
					if (!solve(x3, y3)) {
						continue;
					}
					int c3 = C[x3][y3];
					if (cnt < c1 + c2 + c3) {
						cnt = c1 + c2 + c3;
						z = 64 * k + 8 * j + i;
					}
				}
				C[x2][y2] = c2;
			}
			C[x1][y1] = c1;
		}
		for (int i = 0; i < 3; ++i) {
			int d = z % 8;
			sx += dx[d];
			sy += dy[d];
			bool f{};
			for (int j = 0; j < 8; ++j) {
				if (A[sx][sy][j]) {
					A[sx][sy][j] = 0;
					f = true;
				}
			}
			if (f) {
				D[sx][sy] = S;
			}
			z /= 8;
		}
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				for (int k = 0; k < 8; ++k) {
					A[i][j][k] += B[i][j][k];
				}
			}
		}
	}
	int ans{};
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 8; ++k) {
				ans += A[i][j][k];
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
