#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[6]{-2, -2, 0, 0, 2, 2};
const int dy[6]{-1, 1, -2, 2, -1, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, r1{}, c1{}, r2{}, c2{};
	cin >> N >> r1 >> c1 >> r2 >> c2;
	vector<vector<int>> D(N, vector<int>(N, -1));
	queue<ii> q;
	D[r1][c1] = 0;
	q.push({r1, c1});
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 6; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < N && D[nx][ny] == -1) {
				D[nx][ny] = D[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	cout << D[r2][c2] << "\n";
	return 0;
}
