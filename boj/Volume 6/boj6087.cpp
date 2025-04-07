#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{}, N{};
	cin >> M >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int sx{}, sy{}, gx{}, gy{};
	sx = sy = -1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == 'C') {
				if (sx == -1) {
					sx = i, sy = j;
				} else {
					gx = i, gy = j;
				}
			}
		}
	}
	vector<vector<int>> D(N, vector<int>(M, -1));
	queue<ii> q;
	D[sx][sy] = 0;
	q.push({sx, sy});
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			while (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] != '*') {
				if (D[nx][ny] == -1) {
					D[nx][ny] = D[x][y] + 1;
					q.push({nx, ny});
				}
				nx += dx[i];
				ny += dy[i];
			}
		}
	}
	cout << D[gx][gy] - 1 << "\n";
	return 0;
}
