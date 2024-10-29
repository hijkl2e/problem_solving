#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};
const int INF = 1e9 + 7;

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
	int sx{}, sy{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == '2') {
				sx = i, sy = j;
			}
		}
	}
	vector<vector<int>> D(N, vector<int>(M, -1));
	queue<ii> q;
	D[sx][sy] = 0;
	q.push({sx, sy});
	int ans = INF;
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] != '1' && D[nx][ny] == -1) {
				D[nx][ny] = D[x][y] + 1;
				q.push({nx, ny});
				if (A[nx][ny] > '2') {
					ans = min(ans, D[nx][ny]);
				}
			}
		}
	}
	if (ans == INF) {
		cout << "NIE\n";
	} else {
		cout << "TAK\n";
		cout << ans << "\n";
	}
	return 0;
}
