#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

vector<vector<int>> A(5, vector<int>(5));

int solve(int sx, int sy) {
	vector<vector<int>> D(5, vector<int>(5, -1));
	queue<ii> q;
	D[sx][sy] = 0;
	q.push({sx, sy});
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && A[nx][ny] > -1 && D[nx][ny] == -1) {
				D[nx][ny] = D[x][y] + 1;
				q.push({nx, ny});
			}
			while (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && (A[nx][ny] == 0 || A[nx][ny] == 1)) {
				nx += dx[i];
				ny += dy[i];
			}
			if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && A[nx][ny] == 7) {
				nx += dx[i];
				ny += dy[i];
			}
			nx -= dx[i];
			ny -= dy[i];
			if (D[nx][ny] == -1) {
				D[nx][ny] = D[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	int ret{};
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (A[i][j] == 1) {
				ret = D[i][j];
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> A[i][j];
		}
	}
	int r{}, c{};
	cin >> r >> c;
	cout << solve(r, c) << "\n";
	return 0;
}
