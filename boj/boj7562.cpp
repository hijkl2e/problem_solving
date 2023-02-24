#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[8]{-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[8]{-1, -2, -2, -1, 1, 2, 2, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int L{}, sx{}, sy{}, gx{}, gy{};
		cin >> L >> sx >> sy >> gx >> gy;
		vector<vector<int>> D(L, vector<int>(L, -1));
		queue<ii> q;
		D[sx][sy] = 0;
		q.push({sx, sy});
		while (q.size()) {
			auto [x, y] = q.front(); q.pop();
			for (int i = 0; i < 8; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < L && 0 <= ny && ny < L && D[nx][ny] == -1) {
					D[nx][ny] = D[x][y] + 1;
					q.push({nx, ny});
				}
			}
		}
		cout << D[gx][gy] << "\n";
	}
	return 0;
}
