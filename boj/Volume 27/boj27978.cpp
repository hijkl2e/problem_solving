#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;
const int dx[8]{-1, 0, 1, 1, 1, 0, -1, -1};
const int dy[8]{1, 1, 1, 0, -1, -1, -1, 0};

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
	int sx{}, sy{}, gx{}, gy{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == 'K') {
				sx = i, sy = j;
			} else if (A[i][j] == '*') {
				gx = i, gy = j;
			}
		}
	}
	vector<vector<int>> D(N, vector<int>(M, INF));
	deque<ii> dq;
	D[sx][sy] = 0;
	dq.push_back({sx, sy});
	while (dq.size()) {
		auto [x, y] = dq.front(); dq.pop_front();
		for (int i = 0; i < 8; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] != '#'
					&& D[nx][ny] > D[x][y] + (i > 2)) {
				D[nx][ny] = D[x][y] + (i > 2);
				if (i > 2) {
					dq.push_back({nx, ny});
				} else {
					dq.push_front({nx, ny});
				}
			}
		}
	}
	cout << (D[gx][gy] == INF ? -1 : D[gx][gy]) << "\n";
	return 0;
}
