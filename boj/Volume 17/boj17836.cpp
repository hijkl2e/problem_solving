#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

const int INF = 0x3f3f3f3f;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int D[2][101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, T{};
	cin >> N >> M >> T;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	memset(D, 0x3f, sizeof D);
	queue<iii> q;
	D[0][0][0] = 0;
	q.push({0, 0, 0});
	while (q.size()) {
		auto [z, x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && (A[nx][ny] != 1 || z)) {
				int nz = z | (A[nx][ny] == 2);
				if (D[nz][nx][ny] == INF) {
					D[nz][nx][ny] = D[z][x][y] + 1;
					q.push({nz, nx, ny});
				}
			}
		}
	}
	int ans = min(D[0][N - 1][M - 1], D[1][N - 1][M - 1]);
	if (ans > T) {
		cout << "Fail\n";
	} else {
		cout << ans << "\n";
	}
	return 0;
}
