#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[8]{-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8]{-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<ii>> B(501);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			B[A[i][j]].push_back({i, j});
		}
	}
	vector<deque<bool>> C(N, deque<bool>(M));
	queue<ii> q;
	int ans{};
	for (int k = 500; k >= 0; --k) {
		for (auto &[r, c] : B[k]) {
			if (C[r][c]) {
				continue;
			}
			C[r][c] = true;
			q.push({r, c});
			while (q.size()) {
				auto [x, y] = q.front(); q.pop();
				for (int i = 0; i < 8; ++i) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (0 <= nx && nx < N && 0 <= ny && ny < M && A[x][y] >= A[nx][ny] && !C[nx][ny]) {
						C[nx][ny] = true;
						q.push({nx, ny});
					}
				}
			}
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
