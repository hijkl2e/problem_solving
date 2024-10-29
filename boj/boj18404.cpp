#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[8]{-1, -2, -2, -1, 1, 2, 2, 1};
const int dy[8]{-2, -1, 1, 2, 2, 1, -1, -2};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	int sx{}, sy{};
	cin >> sx >> sy;
	--sx, --sy;
	vector<int> x(M);
	vector<int> y(M);
	for (int i = 0; i < M; ++i) {
		cin >> x[i] >> y[i];
		--x[i], --y[i];
	}
	vector<vector<int>> D(N, vector<int>(N, -1));
	queue<ii> q;
	D[sx][sy] = 0;
	q.push({sx, sy});
	while (q.size()) {
		auto [X, Y] = q.front(); q.pop();
		for (int i = 0; i < 8; ++i) {
			int nx = X + dx[i];
			int ny = Y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < N && D[nx][ny] == -1) {
				D[nx][ny] = D[X][Y] + 1;
				q.push({nx, ny});
			}
		}
	}
	for (int i = 0; i < M; ++i) {
		cout << D[x[i]][y[i]] << (i == M - 1 ? "\n" : " ");
	}
	return 0;
}
