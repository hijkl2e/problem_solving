#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;
const int dx[4]{0, 1, 0, -1};
const int dy[4]{1, 0, -1, 0};

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
	int x1{}, y1{}, x2{}, y2{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == 'A') {
				x1 = i, y1 = j;
			} else if (A[i][j] == 'B') {
				x2 = i, y2 = j;
			}
		}
	}
	if ((x1 + y1 + x2 + y2) % 2) {
		cout << "-1\n";
		return 0;
	}
	vector<vector<int>> D(N, vector<int>(M, INF));
	queue<ii> q;
	D[x1][y1] = 0;
	q.push({x1, y1});
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && A[nx][ny] != 'G' && D[nx][ny] == INF) {
				D[nx][ny] = D[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	int len = 2 * (N + M - 2);
	int ans = INF;
	for (int i = 0; i < len; ++i) {
		if (D[x2][y2] < INF) {
			int r = D[x2][y2] % len;
			ans = min(ans, D[x2][y2] - r + i + (r > i ? len : 0));
		}
		int d = x2 == 0 && y2 < M - 1 ? 0 : y2 == 0 ? 3 : x2 == N - 1 ? 2 : 1;
		x2 += dx[d];
		y2 += dy[d];
	}
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
