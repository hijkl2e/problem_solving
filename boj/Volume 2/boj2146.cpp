#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int N;
vector<vector<int>> A, B;

void dfs(int x, int y, int c) {
	B[x][y] = c;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < N && A[nx][ny] && B[nx][ny] == -1) {
			B[nx][ny] = c;
			dfs(nx, ny, c);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.assign(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	B.assign(N, vector<int>(N, -1));
	int cnt{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] && B[i][j] == -1) {
				dfs(i, j, cnt++);
			}
		}
	}
	queue<ii> q;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j]--) {
				q.push({i, j});
			}
		}
	}
	int ans = INF;
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < N && B[x][y] != B[nx][ny]) {
				if (A[nx][ny] == -1) {
					A[nx][ny] = A[x][y] + 1;
					B[nx][ny] = B[x][y];
					q.push({nx, ny});
				} else {
					ans = min(ans, A[x][y] + A[nx][ny]);
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
