#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N, M;
vector<deque<bool>> A;

int bfs(int sx, int sy) {
	int ret{};
	queue<ii> q;
	A[sx][sy] = false;
	q.push({sx, sy});
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny]) {
				A[nx][ny] = false;
				q.push({nx, ny});
			}
		}
		++ret;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{};
	cin >> N >> M >> K;
	A.assign(N, deque<bool>(M));
	while (K--) {
		int r{}, c{};
		cin >> r >> c;
		A[r - 1][c - 1] = true;
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j]) {
				ans = max(ans, bfs(i, j));
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
