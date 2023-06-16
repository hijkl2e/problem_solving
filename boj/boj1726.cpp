#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

const int INF = 0x3f3f3f3f;
const int dx[4]{0, 1, 0, -1};
const int dy[4]{1, 0, -1, 0};

int D[101][101][4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	int sx{}, sy{}, sd{};
	cin >> sx >> sy >> sd;
	int gx{}, gy{}, gd{};
	cin >> gx >> gy >> gd;
	--sx, --sy, --gx, --gy;
	sd = sd == 1 ? 0 : sd == 2 ? 2 : sd == 3 ? 1 : 3;
	gd = gd == 1 ? 0 : gd == 2 ? 2 : gd == 3 ? 1 : 3;
	memset(D, 0x3f, sizeof D);
	queue<iii> q;
	D[sx][sy][sd] = 0;
	q.push({sx, sy, sd});
	while (q.size()) {
		auto [x, y, d] = q.front(); q.pop();
		int nx = x, ny = y;
		for (int i = 0; i < 3; ++i) {
			nx += dx[d];
			ny += dy[d];
			if (nx == -1 || nx == N || ny == -1 || ny == M || A[nx][ny]) {
				break;
			} else if (D[nx][ny][d] == INF) {
				D[nx][ny][d] = D[x][y][d] + 1;
				q.push({nx, ny, d});
			}
		}
		for (int i = 1; i < 4; i += 2) {
			int nd = (d + i) % 4;
			if (D[x][y][nd] == INF) {
				D[x][y][nd] = D[x][y][d] + 1;
				q.push({x, y, nd});
			}
		}
	}
	cout << D[gx][gy][gd] << "\n";
	return 0;
}
