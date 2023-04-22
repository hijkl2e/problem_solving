#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;
const int dx[4]{1, 0, -1, 0};
const int dy[4]{0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{};
	cin >> R >> C;
	cin.ignore();
	vector<string> A(R);
	for (int i = 0; i < R; ++i) {
		getline(cin, A[i]);
	}
	vector<vector<int>> B(R, vector<int>(C, INF));
	queue<ii> q;
	int sx{}, sy{};
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (A[i][j] == 'J') {
				sx = i, sy = j;
			} else if (A[i][j] == 'F') {
				B[i][j] = 0;
				q.push({i, j});
			}
		}
	}
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			while (0 <= nx && nx < R && 0 <= ny && ny < C && A[nx][ny] != '#' && B[nx][ny] == INF) {
				B[nx][ny] = B[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	vector<vector<int>> D(R, vector<int>(C, INF));
	D[sx][sy] = 0;
	q.push({sx, sy});
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			while (0 <= nx && nx < R && 0 <= ny && ny < C && A[nx][ny] != '#' && D[nx][ny] == INF
					&& D[x][y] + 1 < B[nx][ny]) {
				D[nx][ny] = D[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < R; ++i) {
		ans = min({ans, D[i][0], D[i][C - 1]});
	}
	for (int i = 0; i < C; ++i) {
		ans = min({ans, D[0][i], D[R - 1][i]});
	}
	if (ans == INF) {
		cout << "IMPOSSIBLE\n";
	} else {
		cout << ++ans << "\n";
	}
	return 0;
}
