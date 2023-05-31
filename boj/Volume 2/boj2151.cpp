#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

const int INF = 0x3f3f3f3f;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int D[51][51][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int sx{}, sy{}, gx{}, gy{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] == '#') {
				sx = i, sy = j;
				swap(sx, gx);
				swap(sy, gy);
			}
		}
	}
	memset(D, 0x3f, sizeof D);
	deque<iii> dq;
	D[sx][sy][0] = D[sx][sy][1] = 0;
	dq.push_back({sx, sy, 0});
	dq.push_back({sx, sy, 1});
	while (dq.size()) {
		auto [x, y, z] = dq.front(); dq.pop_front();
		for (int i = 0; i < 2; ++i) {
			int d = 2 * z + i;
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (0 <= nx && nx < N && 0 <= ny && ny < N && A[nx][ny] != '*') {
				if (D[nx][ny][z] > D[x][y][z]) {
					D[nx][ny][z] = D[x][y][z];
					dq.push_front({nx, ny, z});
				}
				if (A[nx][ny] != '!') {
					continue;
				}
				int nz = z ^ 1;
				int nd = D[x][y][z] + 1;
				if (D[nx][ny][nz] > nd) {
					D[nx][ny][nz] = nd;
					dq.push_back({nx, ny, nz});
				}
			}
		}
	}
	int ans = min(D[gx][gy][0], D[gx][gy][1]);
	cout << ans << "\n";
	return 0;
}
