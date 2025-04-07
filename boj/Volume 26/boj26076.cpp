#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[8]{-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8]{-1, 0, 1, 1, 1, 0, -1, -1};
const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(N + 2, vector<int>(M + 2));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < N + M - 1; ++i) {
		A[max(i - M + 1, 0)][min(i + 2, M + 1)] = 1;
		A[min(i + 2, N + 1)][max(i - N + 1, 0)] = 1;
	}
	vector<vector<int>> D(N + 2, vector<int>(M + 2, INF));
	deque<ii> dq;
	D[0][2] = 0;
	dq.push_back({0, 2});
	while (dq.size()) {
		auto [x, y] = dq.front(); dq.pop_front();
		if ((x == N + 1 || y == 0) || D[x][y] == 2) {
			cout << min(D[x][y], 2) << "\n";
			return 0;
		}
		for (int i = 0; i < 8; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N + 2 && 0 <= ny && ny < M + 2
					&& (nx > 1 || ny > 1) && (nx < N || ny < M)) {
				int nd = D[x][y] - A[nx][ny] + 1;
				if (D[nx][ny] > nd) {
					D[nx][ny] = nd;
					if (A[nx][ny]) {
						dq.push_front({nx, ny});
					} else {
						dq.push_back({nx, ny});
					}
				}
			}
		}
	}
	return 0;
}
