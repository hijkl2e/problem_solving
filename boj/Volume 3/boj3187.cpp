#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int R, C;
vector<string> A;
vector<deque<bool>> vst;

int bfs(int sx, int sy) {
	int c1{}, c2{};
	queue<ii> q;
	vst[sx][sy] = true;
	q.push({sx, sy});
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < R && 0 <= ny && ny < C && A[nx][ny] != '#' && !vst[nx][ny]) {
				vst[nx][ny] = true;
				q.push({nx, ny});
			}
		}
		if (A[x][y] == 'k') {
			++c1;
		} else if (A[x][y] == 'v') {
			++c2;
		}
	}
	return c1 > c2 ? c1 : -c2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> R >> C;
	cin.ignore();
	A.resize(R);
	for (int i = 0; i < R; ++i) {
		getline(cin, A[i]);
	}
	vst.assign(R, deque<bool>(C));
	int ans_x{}, ans_y{};
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (A[i][j] != '#' && !vst[i][j]) {
				int res = bfs(i, j);
				if (res > 0) {
					ans_x += res;
				} else {
					ans_y -= res;
				}
			}
		}
	}
	cout << ans_x << " " << ans_y << "\n";
	return 0;
}
