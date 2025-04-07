#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

const int dx[6]{1, -1, 0, 0, 0, 0};
const int dy[6]{0, 0, 1, -1, 0, 0};
const int dz[6]{0, 0, 0, 0, 1, -1};

string A[31][31];
int D[31][31][31];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L{}, R{}, C{};
	while (cin >> L >> R >> C, L) {
		for (int i = 0; i < L; ++i) {
			getline(cin, A[i][0]);
			for (int j = 0; j < R; ++j) {
				getline(cin, A[i][j]);
			}
		}
		int sx{}, sy{}, sz{}, gx{}, gy{}, gz{};
		for (int i = 0; i < L; ++i) {
			for (int j = 0; j < R; ++j) {
				for (int k = 0; k < C; ++k) {
					if (A[i][j][k] == 'S') {
						sx = i, sy = j, sz = k;
					} else if (A[i][j][k] == 'E') {
						gx = i, gy = j, gz = k;
					}
				}
			}
		}
		memset(D, -1, sizeof D);
		queue<iii> q;
		D[sx][sy][sz] = 0;
		q.push({sx, sy, sz});
		while (q.size()) {
			auto [x, y, z] = q.front(); q.pop();
			for (int i = 0; i < 6; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z + dz[i];
				if (0 <= nx && nx < L && 0 <= ny && ny < R && 0 <= nz && nz < C
						&& A[nx][ny][nz] != '#' && D[nx][ny][nz] == -1) {
					D[nx][ny][nz] = D[x][y][z] + 1;
					q.push({nx, ny, nz});
				}
			}
		}
		if (D[gx][gy][gz] == -1) {
			cout << "Trapped!\n";
		} else {
			cout << "Escaped in " << D[gx][gy][gz] << " minute(s).\n";
		}
	}
	return 0;
}
