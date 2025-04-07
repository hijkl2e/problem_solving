#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

const int dx[6]{1, -1, 0, 0, 0, 0};
const int dy[6]{0, 0, 1, -1, 0, 0};
const int dz[6]{0, 0, 0, 0, 1, -1};

int A[101][101][101];
int D[101][101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{}, N{}, H{};
	cin >> M >> N >> H;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				cin >> A[i][j][k];
			}
		}
	}
	queue<iii> q;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				if (A[i][j][k] == 1) {
					q.push({i, j, k});
				}
			}
		}
	}
	while (q.size()) {
		auto [x, y, z] = q.front(); q.pop();
		for (int i = 0; i < 6; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (0 <= nx && nx < H && 0 <= ny && ny < N && 0 <= nz && nz < M && A[nx][ny][nz] == 0) {
				A[nx][ny][nz] = 1;
				D[nx][ny][nz] = D[x][y][z] + 1;
				q.push({nx, ny, nz});
			}
		}
	}
	int ans{};
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				ans = max(ans, D[i][j][k]);
				if (A[i][j][k] == 0) {
					ans = -1;
					i = j = 101;
					break;
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
