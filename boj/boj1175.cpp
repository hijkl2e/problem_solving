#include <bits/stdc++.h>

using namespace std;

using rec = tuple<int, int, int, int, int>;

const int INF = 0x3f3f3f3f;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int D[51][51][4][2][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int sx{}, sy{}, cx1{}, cy1{}, cx2{}, cy2{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == 'S') {
				sx = i, sy = j;
			} else if (A[i][j] == 'C') {
				cx1 = i, cy1 = j;
				swap(cx1, cx2);
				swap(cy1, cy2);
			}
		}
	}
	memset(D, 0x3f, sizeof D);
	queue<rec> q;
	for (int i = 0; i < 4; ++i) {
		D[sx][sy][i][0][0] = 0;
		q.push({sx, sy, i, 0, 0});
	}
	while (q.size()) {
		auto [x, y, d, c1, c2] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			if (i == d) {
				continue;
			}
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] != '#') {
				int nc1 = c1 | (nx == cx1 && ny == cy1);
				int nc2 = c2 | (nx == cx2 && ny == cy2);
				if (D[nx][ny][i][nc1][nc2] == INF) {
					D[nx][ny][i][nc1][nc2] = D[x][y][d][c1][c2] + 1;
					q.push({nx, ny, i, nc1, nc2});
				}
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < 4; ++i) {
		ans = min(ans, D[cx1][cy1][i][1][1]);
		ans = min(ans, D[cx2][cy2][i][1][1]);
	}
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
