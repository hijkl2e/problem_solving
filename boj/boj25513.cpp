#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e8;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

vector<vector<int>> A(5, vector<int>(5));

int solve(int sx, int sy) {
	vector<vector<int>> D(5, vector<int>(5, INF));
	queue<ii> q;
	D[sx][sy] = 0;
	q.push({sx, sy});
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && A[nx][ny] > -1 && D[nx][ny] == INF) {
				D[nx][ny] = D[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	int ret{};
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (A[i][j] == A[sx][sy] + 1) {
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
	int ans = solve(r, c);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (0 < A[i][j] && A[i][j] < 6) {
				ans += solve(i, j);
			}
		}
	}
	cout << (ans < INF ? ans : -1) << "\n";
	return 0;
}
