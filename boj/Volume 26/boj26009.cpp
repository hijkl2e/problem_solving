#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[8]{1, -1, 0, 0, 1, 1, -1, -1};
const int dy[8]{0, 0, 1, -1, 1, -1, -1, 1};
const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<vector<int>> D(N, vector<int>(M, INF));
	while (K--) {
		int r{}, c{}, d{};
		cin >> r >> c >> d;
		--r, --c;
		D[r][c] = -1;
		r -= d;
		for (int i = 4; i < 8; ++i) {
			for (int j = 0; j < d; ++j) {
				if (0 <= r && r < N && 0 <= c && c < M) {
					D[r][c] = -1;
				}
				r += dx[i];
				c += dy[i];
			}
		}
	}
	queue<ii> q;
	D[0][0] = 0;
	q.push({0, 0});
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && D[nx][ny] == INF) {
				D[nx][ny] = D[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	if (D[N - 1][M - 1] == INF) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		cout << D[N - 1][M - 1] << "\n";
	}
	return 0;
}
