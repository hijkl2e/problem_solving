#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

const int INF = 0x3f3f3f3f;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int D[1001][1001][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, sx{}, sy{}, gx{}, gy{};
	cin >> N >> M >> sx >> sy >> gx >> gy;
	--sx, --sy, --gx, --gy;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	memset(D, 0x3f, sizeof D);
	queue<iii> q;
	D[sx][sy][0] = 0;
	q.push({sx, sy, 0});
	while (q.size()) {
		auto [x, y, z] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				int nz = z + A[nx][ny];
				if (nz < 2 && D[nx][ny][nz] == INF) {
					D[nx][ny][nz] = D[x][y][z] + 1;
					q.push({nx, ny, nz});
				}
			}
		}
	}
	int ans = min(D[gx][gy][0], D[gx][gy][1]);
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
