#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

const int dx[8]{1, -1, 0, 0, -1, -1, 1, 1};
const int dy[8]{0, 0, 1, -1, -1, 1, -1, 1};

int N;
vector<string> A;
int D[51][51][2];

bool solve(int cx, int cy, int z, int k) {
	static vector<int> x(3);
	static vector<int> y(3);
	if (k == 4) {
		for (int i = 0; i < 8; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx == -1 || nx == N || ny == -1 || ny == N || A[nx][ny] == '1') {
				return false;
			}
		}
	} else {
		for (int i = 0; i < 3; ++i) {
			x[i] = cx + (z ? (i - 1) : 0);
			y[i] = cy + (z ? 0 : (i - 1));
		}
		for (int i = 0; i < 3; ++i) {
			int nx = x[i] + dx[k];
			int ny = y[i] + dy[k];
			if (nx == -1 || nx == N || ny == -1 || ny == N || A[nx][ny] == '1') {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	cin.ignore();
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int sx{}, sy{}, sz{}, gx{}, gy{}, gz{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] == 'B' && ++sz == 2) {
				sx = i, sy = j;
			} else if (A[i][j] == 'E' && ++gz == 2) {
				gx = i, gy = j;
			}
		}
	}
	sz = sx + 1 < N && A[sx + 1][sy] == 'B';
	gz = gx + 1 < N && A[gx + 1][gy] == 'E';
	memset(D, -1, sizeof D);
	queue<iii> q;
	D[sx][sy][sz] = 0;
	q.push({sx, sy, sz});
	while (q.size()) {
		auto [x, y, z] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < N && D[nx][ny][z] == -1 && solve(x, y, z, i)) {
				D[nx][ny][z] = D[x][y][z] + 1;
				q.push({nx, ny, z});
			}
		}
		if (D[x][y][z ^ 1] == -1 && solve(x, y, z, 4)) {
			D[x][y][z ^ 1] = D[x][y][z] + 1;
			q.push({x, y, z ^ 1});
		}
	}
	cout << (D[gx][gy][gz] == -1 ? 0 : D[gx][gy][gz]) << "\n";
	return 0;
}
